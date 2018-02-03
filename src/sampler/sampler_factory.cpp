#include "sampler_factory.hpp"
#include "mock_sampler.hpp"

namespace Sampler {

SamplerPtr SamplerFactory::get(std::string sampler_name) {
    SamplerPtr sampler;

    if (sampler_name == "mock_sampler") {
        sampler.reset(new MockSampler);
    }

    return sampler;
}

} // namespace Sampler
