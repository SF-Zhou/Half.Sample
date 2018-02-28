#include <algorithm>
#include "processer.hpp"
#include "../constant.hpp"
#include "../global/global.hpp"

namespace Commander {
namespace Processer {

bool align(const Sampler::SamplerConfig &config, Result::SamplingResult &result) {
    result.maximum = *std::max_element(result.buffer, result.buffer + config.sampling_length);
    result.minimum = *std::min_element(result.buffer, result.buffer + config.sampling_length);

    if (result.maximum - result.minimum < Constant::MinVoltageAmplitude) {
        Global::message = "voltage_not_enough";
        return false;
    }

    return true;
}

bool summation(const Sampler::SamplerConfig &config, Result::SamplingResult &result) {
    const double minimum = result.minimum;
    const double maximum = result.maximum;

    const double current_lower_bound = minimum + (maximum - minimum) * Constant::LowerBound;
    const double current_upper_bound = minimum + (maximum - minimum) * Constant::UpperBound;

    for (int j = 0; j < config.waveform_length; j ++) {
        result.wave[j] = 0;
    }

    double base_sum = 0;
    int base_count = 0;

    int copy_times = 0;
    bool under_lower_bound = false;
    for (int i = Constant::CroppedLength; i < config.sampling_length; i ++) {
        const double &value = result.buffer[i];

        if (under_lower_bound) {
            if (value >= current_upper_bound) {
                under_lower_bound = false;

                for (int j = 0; j < Constant::CroppedLength / 2; j ++) {
                    base_sum += result.buffer[i - Constant::CroppedLength + j];
                    base_count++;
                }

                if (i + config.valid_length < config.sampling_length) {
                    for (int j = 0; j < config.valid_length; j ++) {
                        result.wave[j] += result.buffer[i + j];
                    }
                    copy_times ++;
                }
            }
        } else if (value <= current_lower_bound) {
            under_lower_bound = true;
        }
    }

    const double base_value = base_count ? base_sum / base_count : 0;
    for (int j = 0; j < config.valid_length; j ++) {
        result.wave[j] = result.wave[j] / copy_times - base_value;
    }
    return true;
}

bool average(const Sampler::SamplerConfig &config, Result::SamplingResult &result) {
    result.average_length = 0;
    int average_times = config.valid_length / Constant::MaxAverageSize + 1;

    for (int i = average_times; i <= config.valid_length; i += average_times) {
        double sum = 0;

        for (int j = i - average_times; j < i; j ++) {
            sum += result.wave[j];
        }

        result.average[result.average_length ++] = sum / average_times;
    }

    return true;
}

} // namespace Processer
} // namespace Commander
