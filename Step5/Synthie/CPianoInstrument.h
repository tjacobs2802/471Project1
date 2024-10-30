#pragma once
#include "Instrument.h"
#include <vector>
#include <map>

class CPianoInstrument : public CInstrument {
public:
    const double NUM_SECS_IN_MINUTE = 60.0;
    CPianoInstrument(double bpm);
    virtual ~CPianoInstrument();

    virtual void Start() override;
    virtual bool Generate() override;
    virtual void SetNote(CNote* note) override;
    void LoadSample(int midiNote, const std::string& filePath);

private:
    std::map<int, std::vector<double>> m_samples; // Map MIDI note to audio samples
    std::vector<double> m_currentSample;
    size_t m_sampleIndex;
    double m_duration;
    double m_time;
};


