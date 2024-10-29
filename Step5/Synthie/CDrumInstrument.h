#pragma once
#include "Instrument.h"
#include <vector>
#include <map>
#include <string>

class CDrumInstrument : public CInstrument {
public:
    const double NUM_SECS_IN_MINUTE = 60.0;
    CDrumInstrument(double bpm);
    virtual ~CDrumInstrument();

    virtual void Start() override;
    virtual bool Generate() override;
    virtual void SetNote(CNote* note) override;
    void LoadDrumSample(int drumType, const std::string& filePath);

private:
    std::map<int, std::vector<double>> m_drumSamples; // Map drum types to samples
    std::vector<double> m_currentSample;  // Current playing sample
    size_t m_sampleIndex;                 // Track the current sample position
    double m_duration;                    // Note duration
    double m_time;                        // Time tracker
};