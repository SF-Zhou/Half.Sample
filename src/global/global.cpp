#include "global.hpp"

Result::SamplingResult Global::result;
Sampler::SamplerConfig Global::config;
Sampler::SamplerPtr Global::sampler;

bool Global::measuring = false;
bool Global::success = true;
std::string Global::message;
