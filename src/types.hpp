#ifndef TYPES_HPP
#define TYPES_HPP

#include <vector>
#include <memory>

typedef std::vector<double> Vector;
typedef std::shared_ptr<Vector> VectorPtr;

struct Waveform {
    VectorPtr values;
    double interval;

    Waveform(VectorPtr values, double interval): values(values), interval(interval) {}
};

#endif
