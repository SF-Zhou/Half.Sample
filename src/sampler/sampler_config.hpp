#ifndef SAMPLER_CONFIG_HPP
#define SAMPLER_CONFIG_HPP

namespace Sampler {

struct SamplerConfig {
    double sampling_frequency;  // Hz
    double emitting_frequency;  // Hz
    double sampling_interval;  // us

    int sampling_length;
    int waveform_length;
    int valid_length;
    int number_of_waveforms;

    double mock_tau;  // us
    double mock_v0;  // V
    double mock_v_inf;  // V

    SamplerConfig();
    void update(int number_of_waveforms, double emitting_frequency);
};

} // namespace Sampler

#endif
