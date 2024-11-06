#pragma once
#include "Instrument.h"
#include "AR.h"
#include "Waveform.h"

class CWavetable : public CInstrument
{
public:
    CWavetable();

    const double NUM_SECS_IN_MINUTE = 60.0;

    virtual void Start();
    virtual bool Generate();

    void SetNoteSample(const CComVariant& value, bool isGlissando);
    void SetNote(CNote* note);

private:
    CWaveform m_waveform;
    CAR m_ar;
    double m_time;
};
