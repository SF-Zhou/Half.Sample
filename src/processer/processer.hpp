#ifndef PROCESSER_HPP
#define PROCESSER_HPP

#include "../result/sampling_result.hpp"
#include "../sampler/sampler_config.hpp"

namespace Processer {

bool align(const Sampler::SamplerConfig &config, Result::SamplingResult &result);

} // namespace Processer

#endif
