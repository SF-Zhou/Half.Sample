#include <iostream>
#include "sampler/sampler_factory.hpp"
using namespace std;

double buffer[100000];

int main() {
    Sampler::SamplerPtr sampler = Sampler::SamplerFactory::get("mock_sampler");
    bool ret = sampler->sample(1000, int(2e7), buffer);
    std::cout << ret << std::endl;
}
