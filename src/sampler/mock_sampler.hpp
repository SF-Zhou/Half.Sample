#ifndef MOCK_SAMPLER_HPP
#define MOCK_SAMPLER_HPP

#include "sampler.hpp"

namespace Sampler {

class MockSampler: public Sampler {
    public:
    virtual bool sample(const SamplerConfig &config, Result::SamplingResult &result);
    virtual std::string name();
};

} // namespace Sampler

#endif
