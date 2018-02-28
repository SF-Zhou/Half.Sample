#ifndef SAMPLER_CONFIG_HPP
#define SAMPLER_CONFIG_HPP

namespace Sampler {

struct SamplerConfig {
    double sampling_frequency;  // Hz
    double emitting_frequency;  // Hz

    int sampling_length;
    int waveform_length;
    int number_of_waveforms;

    double mock_tau;  // us

    void update(int number_of_waveforms, double emitting_frequency);
};

} // namespace Sampler

#endif
