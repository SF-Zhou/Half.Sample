#ifndef sampling_config_HPP
#define sampling_config_HPP

namespace Config {

struct SamplingConfig {
    double sampling_frequency;  // Hz
    double emitting_frequency;  // Hz
    double sampling_interval;  // us

    int sampling_length;
    int waveform_length;
    int valid_length;
    int number_of_waveforms;

    void update(int number_of_waveforms, double emitting_frequency);
};

} // namespace Sampler

#endif
