#ifndef SAMPLER_HPP
#define SAMPLER_HPP

#include <iostream>
#include <memory>
#include <string>
#include "sampler_config.hpp"
#include "../result/sampling_result.hpp"

namespace Sampler {

class Sampler {
    public:
    virtual bool sample(const SamplerConfig &config, Result::SamplingResult &result) = 0;
    virtual std::string name() = 0;
};

typedef std::shared_ptr<Sampler> SamplerPtr;

} // namespace Sampler

#endif
