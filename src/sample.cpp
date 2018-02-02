#include "constant.hpp"
#include "result/sampling_result.hpp"
#include "sampler/sampler_factory.hpp"
#include "commander/commander.hpp"

namespace Global {
    Result::SamplingResult result;
    Sampler::SamplerConfig config;
    Sampler::SamplerPtr sampler = Sampler::SamplerFactory::get("mock_sampler");
}

int main() {
    Commander::exec();
}
