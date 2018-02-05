#include <algorithm>
#include "processer.hpp"

namespace Processer {

bool align(const Sampler::SamplerConfig &config, Result::SamplingResult &result) {
    result.maximum = *std::max_element(result.buffer, result.buffer + config.sampling_length);
    result.minimum = *std::min_element(result.buffer, result.buffer + config.sampling_length);

    return true;
}

} // namespace Processer
