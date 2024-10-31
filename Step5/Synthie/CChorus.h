#pragma once
#include "CEffect.h"
#include <vector>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// CChorus class for implementing chorus effect
class CChorus : public CEffect {
private:
    double m_amplitude;
    double m_frequency;
    double m_phase;
    double m_balanceOffset;
    double m_wetness;
    double m_delay;
    std::vector<double> m_frameHistory;
    int m_bufferIndex;
    int m_bufferSize;

public:
    CChorus(int channels, double sampleRate, double samplePeriod);

    // Process method to apply chorus effect
    virtual void Process(const double* frameIn, double* frameOut, const double& time) override;

    // Method to load attributes from XML
    virtual void XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value) override;

    // Method to reset the effect
    void Reset() override;
};
