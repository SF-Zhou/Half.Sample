#include "base.hpp"

namespace Commander {
namespace Base {

    // ### 1.1 Output
    // output various values to stdout
    void output(bool value) {
        printf (value ? "True" : "False");
    }

    void output(std::string value) {
        std::cout << "\"" << value << "\"";
    }

    void output(int value) {
        printf("%d", value);
    }

    void output(double value) {
        printf("%f", value);
    }

    // ### 1.2 Line
    // print a full line like "index = 100"
    void line(std::string name, bool value) {
        std::cout << name << " = ";
        output(value);
        std::cout << std::endl;
    }

    void line(std::string name, std::string value) {
        std::cout << name << " = ";
        output(value);
        std::cout << std::endl;
    }

    void line(std::string name, int value) {
        std::cout << name << " = ";
        output(value);
        std::cout << std::endl;
    }

    void line(std::string name, double value) {
        std::cout << name << " = ";
        output(value);
        std::cout << std::endl;
    }

    // ### 1.3 Error & End Mark
    void error(std::string message) {
        line("error", true);
        variable(message);
    }

    void command_not_found() {
        error("command_not_found");
    }

    void end() {
        std::cout << "EOF" << std::endl;
    }

} // namespace Base
} // namespace Commander
