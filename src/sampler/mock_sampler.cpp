#include <cmath>
#include <ctime>
#include <iostream>
#include "mock_sampler.hpp"

namespace Sampler {

bool MockSampler::sample(const SamplerConfig &config, Result::SamplingResult &result) {
    auto buffer = result.buffer;

    for (int i = 0; i < config.number_of_waveforms + 1; i++) {
        auto current = buffer + config.waveform_length * i;

        for (int j = 0; j < config.waveform_length; j++) {
            if (j < 5) {
                current[j] = j * config.mock_v0 / 5;
            } else if (j < config.waveform_length / 2) {
                double b = config.mock_v_inf;
                double w = config.mock_v0 - b;
                current[j] = b + w * exp((5 - j) * config.sampling_interval / config.mock_tau);
            } else if (j < config.waveform_length / 2 + 5) {
                current[j] = (5 - j + config.waveform_length / 2) * config.mock_v_inf / 5;
            } else {
                current[j] = 0;
            }
        }
    }

    // random noise
    srand(time(0));
    for (int i = 0; i < config.sampling_length; i++) {
        buffer[i] += (rand() / double(RAND_MAX) - 0.5) * config.mock_noise;
    }

    // vertical shift
    const double max_shift_amplitude = -2.5;
    const double shift_amplitude = rand() / double(RAND_MAX) * max_shift_amplitude;
    for (int i = 0; i < config.sampling_length; i++) {
        buffer[i] += shift_amplitude;
    }

    return true;
}

std::string MockSampler::name() {
    return "mock_sampler";
}

} // namespace Sampler
