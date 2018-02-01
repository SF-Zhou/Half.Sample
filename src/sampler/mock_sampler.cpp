#include "iostream"
#include "mock_sampler.hpp"

namespace Sampler {

bool MockSampler::sample(const SamplerConfig &config, Result::AbstractResult &result) {
    double *buffer = result.get_buffer();

    std::cout << "[Sampler::MockSampler::sample]" << std::endl;
    return true;
}

} // namespace Sampler
