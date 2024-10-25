#pragma once

#include "AudioEffect.h"
#include "Note.h"
#include <comdef.h>
#include <vector>

class EchoEffect : public AudioEffect {
public:
    EchoEffect(); // Constructor
    void SetNote(const CNote* note) override;
    void Process(double* frameIn, double* frameOut) override;

private:
    double m_wet;   // Wet mix
    double m_dry;   // Dry mix
    double m_delay; // Delay in seconds

    // New members for delay buffer management
    std::vector<double> m_delayBuffer; // Circular buffer for delayed samples
    int m_delaySamples; // Number of samples for the delay
    int m_writeIndex; // Index for writing to the buffer
};
