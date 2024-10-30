#pragma once

#include "Instrument.h"
#include "SineWave.h"
#include "AR.h"
#include <vector>
#include <string>

class CDrumInstrument : public CInstrument {
public:

    const double NUM_SECS_IN_MINUTE = 60.0;

    CDrumInstrument(double bpm);
    virtual ~CDrumInstrument();

    virtual void Start() override;
    virtual bool Generate() override;
    void GenerateSyntheticDrum();
    virtual void SetNote(CNote* note) override;

private:
    void LoadDrumSample(const std::wstring& drumName);
    std::vector<double> m_currentSample;

    size_t m_sampleIndex;
    double m_duration;
    double m_time;
    CSineWave   m_sinewave;
    CAR m_ar;  // Attack/Release envelope generator
};