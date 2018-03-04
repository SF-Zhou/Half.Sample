#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

namespace Commander {
namespace Base {

    void line(std::string name, bool value);
    void line(std::string name, std::string value);
    void line(std::string name, int value);
    void line(std::string name, double value);
    #define variable(var) line(#var, var);

    void error(std::string message);
    void command_not_found();
    void end();

} // namespace Base
} // namespace Commander

#endif
