#ifndef CONSTANT_HPP
#define CONSTANT_HPP

namespace Constant {
    const int MaxSamplingFrequency = int(2e7);  // Hz
    const int MaxBufferSize = MaxSamplingFrequency * 2;  // sample 2 second in max speed

    const double MinVoltageAmplitude = 0.4;  // unit: V
}

#endif
