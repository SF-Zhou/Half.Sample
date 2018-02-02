#include "constant.hpp"
#include "result/sampling_result.hpp"
#include "sampler/sampler_factory.hpp"

namespace Global {
    Result::SamplingResult result;
    Sampler::SamplerConfig config;
    Sampler::SamplerPtr sampler = Sampler::SamplerFactory::get("mock_sampler");
}

int main() {
    Global::config.update(2, 200);
    Global::sampler->sample(Global::config, Global::result);
}
