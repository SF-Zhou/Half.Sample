#include "measure.hpp"
#include "base.hpp"
#include "../global/global.hpp"

namespace Commander {

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
    }

    void is_measuring() {
        bool &measuring = Global::measuring;
        Base::variable(measuring);
    }

} // namespace Commander
