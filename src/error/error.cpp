#include "error.hpp"

namespace Error {

    std::string to_string(Code error_code) {
        switch (error_code) {
            case SUCCESS:
                return "success";
            case COMMAND_NOT_FOUND:
                return "command_not_found";
            case SAMPLER_NOT_FOUND:
                return "sampler_not_found";
            case NOW_IN_MEASURING:
                return "now_in_measuring";
            case VOLTAGE_NOT_ENOUGH:
                return "voltage_not_enough";
            case REAL_SAMPLER_ERROR:
                return "real_sampler_error";
            case WAVE_NOT_FOUND:
                return "wave_not_found";
            case APPROPRIATE_WAVE_NOT_FOUND:
                return "appropriate_wave_not_found";
        }

        return "error_not_found";
    }

} // namespace Error
