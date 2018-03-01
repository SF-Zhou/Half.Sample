#include <thread>
#include <chrono>
#include "measure.hpp"
#include "base.hpp"
#include "../global/global.hpp"
#include "../processer/processer.hpp"

namespace Commander {
    void measure() {
        bool &success = Global::success;
        success = true;

        do {
            success = Global::sampler->sample(Global::config, Global::result);
            if (!success) break;

            success = Processer::align(Global::config, Global::result);
            if (!success) break;

            success = Processer::summation(Global::config, Global::result);
            if (!success) break;

            success = Processer::estimate(Global::config, Global::result);
            if (!success) break;
        } while (false);

        Global::measuring = false;
    }

    void to_query() {
        bool success = Global::success;
        Base::variable(success);

        if (success) {
            double maximum = Global::result.maximum;
            double minimum = Global::result.minimum;
            Base::variable(maximum);
            Base::variable(minimum);

            const double sampling_interval = Global::config.sampling_interval;
            Base::variable(sampling_interval);
            const double average_interval = Global::result.average_interval;
            Base::variable(average_interval);

            const double tau = Global::result.estimate.tau;
            Base::variable(tau);
            const double w = Global::result.estimate.w;
            Base::variable(w);
            const double b = Global::result.estimate.b;
            Base::variable(b);
            const double loss = Global::result.estimate.loss;
            Base::variable(loss);

            printf("average = [");
            for (int i = 0; i < Global::result.average_length; i ++) {
                printf("%.3f,", Global::result.average[i]);
            }
            printf("]\n");
        } else {
            std::string &message = Global::message;
            Base::variable(message);
        }
    }

    void to_measure() {
        int number_of_waveforms;
        double emitting_frequency;
        std::cin >> number_of_waveforms;
        std::cin >> emitting_frequency;
        Global::config.update(number_of_waveforms, emitting_frequency);

        bool &measuring = Global::measuring;
        if (measuring) {
            Base::error("now_in_measuring");
            return;
        }

        measuring = true;
        Base::variable(measuring);

        // start a thread to do measure
        std::thread(measure).detach();
    }

    void is_measuring() {
        bool &measuring = Global::measuring;
        Base::variable(measuring);
    }

} // namespace Commander
