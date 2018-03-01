#ifndef SAMPLING_RESULT_HPP
#define SAMPLING_RESULT_HPP

#include "../constant.hpp"

namespace Result {

struct SamplingResult {
    double buffer[Constant::MaxBufferSize];
    double wave[Constant::MaxBufferSize / 16];

    double average[Constant::MaxAverageSize];
    double average_interval;
    int average_length;

    double maximum, minimum;
};

} // namespace Result;

#endif
