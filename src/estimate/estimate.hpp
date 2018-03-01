#ifndef ESTIMATE_HPP
#define ESTIMATE_HPP

#include "../types.hpp"

namespace Estimate {

struct EstimatedResult {
    double tau;
    double w, b;
    double loss;
    VectorPtr x;
    VectorPtr y;

    EstimatedResult() {};
    EstimatedResult(VectorPtr x, VectorPtr y, double tau);

    void calculate_para();
    void calculate_loss();
};

EstimatedResult one_third_search(VectorPtr x, VectorPtr y);

} // namespace Estimate

#endif
