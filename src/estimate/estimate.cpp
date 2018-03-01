#include <cmath>
#include "estimate.hpp"
#include "../constant.hpp"

namespace Estimate {

    EstimatedResult::EstimatedResult(VectorPtr x, VectorPtr y, double tau): tau(tau), x(x), y(y) {
        calculate_para();
        calculate_loss();
    };

    void EstimatedResult::calculate_para() {
        int m = y->size();

        double sum_x = 0, sum_y = 0;
        double sum_xx = 0, sum_xy = 0;

        for (int i = 0; i < m ; i++) {
            double vx = exp((*x)[i] / -tau);
            double vy = (*y)[i];

            sum_x += vx;
            sum_y += vy;
            sum_xx += vx * vx;
            sum_xy += vx * vy;
        }

        double mean_x = sum_x / m;
        double mean_y = sum_y / m;

        w = (sum_xy / m - mean_x * mean_y) / (sum_xx / m - mean_x * mean_x);
        b = mean_y - w * mean_x;
    }

    void EstimatedResult::calculate_loss() {
        int m = y->size();

        double loss_sum = 0;
        for (int i = 0; i < m; i++) {
            loss_sum += pow(exp((*x)[i] / -tau) * w + b - (*y)[i], 2);
        }

        loss = loss_sum / m;
    }

    EstimatedResult one_third_search(VectorPtr x, VectorPtr y) {
        double l = 0.01, r = 1e4;  // range of tau

        while (l + Constant::SearchEpsilon < r) {
            double tau_l = (l + l + r) / 3;
            double tau_r = (l + r + r) / 3;

            EstimatedResult estimate_l(x, y, tau_l);
            EstimatedResult estimate_r(x, y, tau_r);

            if (estimate_l.loss < estimate_r.loss) {
                r = tau_r;
            } else {
                l = tau_l;
            }
        }

        return EstimatedResult(x, y, (l + r) / 2);
    }

} // namespace Estimate
