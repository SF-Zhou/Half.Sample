#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include "../result/sampling_result.hpp"
#include "../sampler/sampler.hpp"
#include "../sampler/sampler_config.hpp"

class Global {
    public:
    static Result::SamplingResult result;
    static Sampler::SamplerConfig config;
    static Sampler::SamplerPtr sampler;
};

#endif
