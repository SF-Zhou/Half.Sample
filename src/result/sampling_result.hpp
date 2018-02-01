#ifndef SAMPLING_RESULT_HPP
#define SAMPLING_RESULT_HPP

#include "abstract_result.hpp"

namespace Result {

template<int BufferSize>
class SamplingResult: public AbstractResult {
    public:
    virtual double *get_buffer() {
        return buffer;
    }

    private:
    double buffer[BufferSize];
};

} // namespace Result;

#endif
