#include <iostream>
#include "result/sampling_result.hpp"
#include "sampler/sampler_factory.hpp"
using namespace std;

const int MaxBufferSize = 1000;
Result::SamplingResult<MaxBufferSize> result;


int main() {
    Sampler::SamplerConfig config;
    config.sampling_frequency = int(2e7);
    config.sampling_length = 1000;
    config.number_of_waveforms = 2;

    Sampler::SamplerPtr sampler = Sampler::SamplerFactory::get("mock_sampler");
    bool ret = sampler->sample(config, result);
    std::cout << ret << std::endl;
}
