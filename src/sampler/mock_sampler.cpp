#include <cmath>
#include <iostream>
#include "mock_sampler.hpp"

namespace Sampler {

bool MockSampler::sample(const SamplerConfig &config, Result::SamplingResult &result) {
    auto buffer = result.buffer;

    for (int i = 0; i < config.number_of_waveforms; i++) {
        auto current = buffer + config.waveform_length * i;

        for (int j = 0; j < config.waveform_length; j++) {
            if (j < 5) {
                current[j] = j * 0.5;
            } else if (j < config.waveform_length / 2) {
                current[j] = 5.0 - 2.5 * exp((5 - j) / config.mock_tau);
            } else if (j < config.waveform_length / 2 + 5) {
                current[j] = (5 - j + config.waveform_length / 2) * 1.0;
            } else {
                current[j] = 0;
            }
        }
    }

    return true;
}

std::string MockSampler::name() {
    return "mock_sampler";
}

} // namespace Sampler
