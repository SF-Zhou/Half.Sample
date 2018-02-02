#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

namespace Commander {

class Base {
    public:

    // ### 1.1 Output
    // output various values to stdout
    static void output(bool value) {
        printf (value ? "True" : "False");
    }

    static void output(std::string value) {
        std::cout << "\"" << value << "\"";
    }

    template<typename T>
    static void output(T value) {
        std::cout << value;
    }

    // ### 1.2 Line
    // print a full line like "index = 100"
    template<typename T>
    static void line(std::string name, T value) {
        std::cout << name << " = ";
        output(value);
        std::cout << std::endl;
    }

    #define variable(var) line(#var, var);

    // ### 1.3 Error & End Mark
    static void error(std::string msg) {
        line("error", true);
        variable(msg);
    }

    static void cmd_not_found() {
        error("cmd_not_found");
    }

    static void end() {
        std::cout << "EOF" << std::endl;
    }
};

} // namespace Commander

#endif
