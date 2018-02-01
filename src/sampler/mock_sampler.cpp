#include "iostream"
#include "mock_sampler.hpp"

namespace Sampler {

bool MockSampler::sample(int length, int frequency, double *buffer) {
    std::cout << "[Sampler::MockSampler::sample]" << std::endl;
    return true;
}

} // namespace Sampler
