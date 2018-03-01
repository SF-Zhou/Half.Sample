#ifndef PROCESSER_HPP
#define PROCESSER_HPP

#include "../result/sampling_result.hpp"
#include "../sampler/sampler_config.hpp"

namespace Commander {
namespace Processer {

bool align(const Sampler::SamplerConfig &config, Result::SamplingResult &result);
bool summation(const Sampler::SamplerConfig &config, Result::SamplingResult &result);
bool estimate(const Sampler::SamplerConfig &config, Result::SamplingResult &result);
bool average(const Sampler::SamplerConfig &config, Result::SamplingResult &result);

} // namespace Processer
} // namespace Commander

#endif
