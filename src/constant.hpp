#ifndef CONSTANT_HPP
#define CONSTANT_HPP

namespace Constant {
    const int MaxSamplingFrequency = int(2e7);
    const int MaxBufferSize = MaxSamplingFrequency * 2;  // sample 2 second in max speed
}

#endif
