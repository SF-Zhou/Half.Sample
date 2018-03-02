#include <unordered_map>
#include <functional>
#include <string>
#include "commander.hpp"
#include "measure.hpp"
#include "../global/global.hpp"
#include "../sampler/sampler_factory.hpp"

namespace Commander {

void simple_test() {
    bool success = true;
    Base::variable(success);
}

void set_sampler() {
    std::string sampler_name;
    std::cin >> sampler_name;

    Global::sampler = Sampler::SamplerFactory::get(sampler_name);
    if (Global::sampler.get()) {
        Base::variable(sampler_name);
    } else {
        Base::error("sampler_not_found");
    }
}

void get_sampler() {
    std::string sampler_name;

    if (Global::sampler) {
        sampler_name = Global::sampler->name();
    }

    Base::variable(sampler_name);
}

void set_mock_tau() {
    double &mock_tau = Global::config.mock_tau;
    std::cin >> mock_tau;
    Base::variable(mock_tau);
}

void get_mock_tau() {
    double &mock_tau = Global::config.mock_tau;
    Base::variable(mock_tau);
}

void set_mock_voltage() {
    double &mock_v0 = Global::config.mock_v0;
    double &mock_v_inf = Global::config.mock_v_inf;
    std::cin >> mock_v0 >> mock_v_inf;
    Base::variable(mock_v0);
    Base::variable(mock_v_inf);
}

void get_mock_voltage() {
    double &mock_v0 = Global::config.mock_v0;
    double &mock_v_inf = Global::config.mock_v_inf;
    Base::variable(mock_v0);
    Base::variable(mock_v_inf);
}

void exec() {
    std::unordered_map<std::string, std::function<void (void)> > mapper;

    #define add_func_into_mapper(func, mapper) mapper[#func] = func
    add_func_into_mapper(simple_test, mapper);
    add_func_into_mapper(set_sampler, mapper);
    add_func_into_mapper(get_sampler, mapper);

    add_func_into_mapper(set_mock_tau, mapper);
    add_func_into_mapper(get_mock_tau, mapper);
    add_func_into_mapper(set_mock_voltage, mapper);
    add_func_into_mapper(get_mock_voltage, mapper);

    add_func_into_mapper(to_query, mapper);
    add_func_into_mapper(to_measure, mapper);
    add_func_into_mapper(is_measuring, mapper);

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
