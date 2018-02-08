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

} // namespace Processer
} // namespace Commander
