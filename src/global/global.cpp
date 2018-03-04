#include "global.hpp"

Sampler::SamplerPtr Global::sampler;
Config::SamplingConfig Global::config;
Result::SamplingResult Global::result;

bool Global::measuring = false;
bool Global::success = true;
bool Global::auto_mode = true;
std::string Global::message;
