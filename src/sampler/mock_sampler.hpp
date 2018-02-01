#ifndef MOCK_SAMPLER_HPP
#define MOCK_SAMPLER_HPP

#include "sampler.hpp"

namespace Sampler {

class MockSampler: public Sampler {
    public:
    virtual bool sample(int length, int frequency, double *buffer);
};

} // namespace Sampler

#endif
