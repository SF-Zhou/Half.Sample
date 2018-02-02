#ifndef SAMPLER_CONFIG_HPP
#define SAMPLER_CONFIG_HPP

#include "../constant.hpp"

namespace Sampler {

struct SamplerConfig {
    double sampling_frequency;  // Hz
    double emitting_frequency;  // Hz

    int sampling_length;
    int waveform_length;
    int number_of_waveforms;

    double mock_tau;  // us

    void update(int number_of_waveforms, double emitting_frequency) {
        this->number_of_waveforms = number_of_waveforms;
        this->emitting_frequency = emitting_frequency;

        this->sampling_frequency = Constant::MaxSamplingFrequency;
        if ((number_of_waveforms + 1) / emitting_frequency > 0.5) {
            this->sampling_frequency /= 20;
        }

        this->waveform_length = int(sampling_frequency / emitting_frequency);
        this->sampling_length = this->waveform_length * (number_of_waveforms + 1);
    }
};

} // namespace Sampler

#endif
