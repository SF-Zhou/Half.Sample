#include "sampler_config.hpp"
#include "../constant.hpp"

namespace Sampler {

    void SamplerConfig::update(int number_of_waveforms, double emitting_frequency) {
        this->number_of_waveforms = number_of_waveforms;
        this->emitting_frequency = emitting_frequency;

        if (emitting_frequency >= 10) {
            this->sampling_frequency = Constant::MaxSamplingFrequency;
        } else {
            this->sampling_frequency = Constant::MinSamplingFrequency;
        }

        this->sampling_interval = 1e6 / this->sampling_frequency;
        this->waveform_length = int(sampling_frequency / emitting_frequency);
        this->sampling_length = this->waveform_length * (number_of_waveforms + 1);

        int cropped_length = Constant::CroppedLength * this->sampling_frequency / Constant::MaxSamplingFrequency;
        this->valid_length = waveform_length / 2 - cropped_length;
    }

} // namespace Samper
