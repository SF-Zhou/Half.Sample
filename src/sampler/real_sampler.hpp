#ifndef REAL_SAMPLER_HPP
#define REAL_SAMPLER_HPP

#include "sampler.hpp"

#include "Windows.h"
#include "bdaqctrl.h"
using namespace std;
using namespace Automation::BDaq;

#define deviceDescription L"PCI-1714,BID#0"
#define check_code(code) if (BioFailed(code)) { /* error_code = code; */ return false; }

namespace Sampler {

class RealSampler: public Sampler {
    public:
    virtual bool sample(const SamplerConfig &config, Result::SamplingResult &result) {
        ErrorCode code = Success;
        BufferedAiCtrl *bfdAiCtrl = AdxBufferedAiCtrlCreate();

        // connect device
        DeviceInformation devInfo(deviceDescription);
        code = bfdAiCtrl->setSelectedDevice(devInfo);
        check_code(code);

        // dynamic range setting
        AiChannelCollection* channels = bfdAiCtrl->getChannels();
        channels->getItem(0).setValueRange(V_Neg5To5);

        // sampling rate setting
        ConvertClock * convertClock = bfdAiCtrl->getConvertClock();
        convertClock->setRate(config.sampling_frequency);

        // sampling data
        ScanChannel* scanChannel = bfdAiCtrl->getScanChannel();
        code = scanChannel->setChannelStart(0);
        check_code(code);
        code = scanChannel->setChannelCount(1);
        check_code(code);
        code = scanChannel->setSamples(config.sampling_length);
        check_code(code);
        code = bfdAiCtrl->Prepare();
        check_code(code);
        code = bfdAiCtrl->RunOnce();
        check_code(code);
        code = bfdAiCtrl->GetData(config.sampling_length, result.buffer);
        check_code(code);

        bfdAiCtrl->Dispose();
        return true;
    }

    virtual double get_value(const std::string &key) {
        return 0.0;
    }

    virtual bool set_value(const std::string &key, const double value) {
        return true;
    }

    virtual std::string name() {
        return "real_sampler";
    }
};

} // namespace Sampler

#endif