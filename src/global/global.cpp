#include "global.hpp"

Result::SamplingResult Global::result;
Sampler::SamplerConfig Global::config;
Sampler::SamplerPtr Global::sampler;

bool Global::measuring = false;
bool Global::success = true;
bool Global::auto_mode = true;
std::string Global::message;
