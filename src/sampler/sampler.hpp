#ifndef SAMPLER_HPP
#define SAMPLER_HPP

#include <iostream>
#include <memory>
#include <string>
#include "../config/sampling_config.hpp"
#include "../result/sampling_result.hpp"

namespace Sampler {

class Sampler {
    public:
    virtual bool sample(const Config::SamplingConfig &config, Result::SamplingResult &result) = 0;
    virtual std::string name() = 0;

    virtual double get_value(const std::string &key) = 0;
    virtual bool set_value(const std::string &key, const double value) = 0;
};

typedef std::shared_ptr<Sampler> SamplerPtr;

} // namespace Sampler

#endif
