#ifndef SAMPLER_HPP
#define SAMPLER_HPP

namespace Sampler {

class Sampler {
    public:
    virtual bool sample(int length, int frequency, double *buffer) = 0;
};

typedef std::shared_ptr<Sampler> SamplerPtr;

} // namespace Sampler

#endif
