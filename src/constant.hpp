#ifndef CONSTANT_HPP
#define CONSTANT_HPP

namespace Constant {
    const int MaxSamplingFrequency = int(2e7);  // Hz
    const int MinSamplingFrequency = int(1e6);  // Hz

    const int CroppedLength = 300;

    const int MaxBufferSize = MaxSamplingFrequency * 2;  // sample 2 second in max speed
    const int MaxAverageSize = 1000;

    const double MinVoltageAmplitude = 0.4;  // unit: V
    const double UpperBound = 0.4;  // percent
    const double LowerBound = 0.1;  // percent
}

#endif
