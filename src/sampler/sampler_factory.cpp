#include "sampler_factory.hpp"
#include "mock_sampler.hpp"

namespace Sampler {

SamplerPtr SamplerFactory::get(std::string sampler_name) {
    SamplerPtr sampler;

    if (sampler_name == "mock_sampler") {
        sampler.reset(new MockSampler);
    } else {
        std::cerr << "[Error] Wrong Sampler Name: " << sampler_name << std::endl;
        exit(1);
    }

    return sampler;
}

} // namespace Sampler
