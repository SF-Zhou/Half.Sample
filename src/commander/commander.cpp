#include <unordered_map>
#include <functional>
#include <string>
#include "commander.hpp"

namespace Commander {

void simple_test() {
    bool success = true;
    Base::variable(success);
}

void exec() {
    std::unordered_map<std::string, std::function<void (void)> > mapper;

    #define add_func_into_mapper(func, mapper) mapper[#func] = func
    add_func_into_mapper(simple_test, mapper);

    std::string command;
    while (std::cin >> command) {
        if (mapper.count(command)) {
            mapper[command]();
        } else {
            Base::command_not_found();
        }
        Base::end();
    }
}

} // namespace Commander
