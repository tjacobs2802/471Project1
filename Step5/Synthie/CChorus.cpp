#include "stdafx.h"
#include "CChorus.h"
#include <cmath>

CChorus::CChorus(int channels, double sampleRate, double samplePeriod)
    : CEffect(channels, sampleRate, samplePeriod) {
    m_frequency = 1;
    m_amplitude = 1;
    m_phase = 0;
    m_balanceOffset = 0;
    m_wetness = 0.5;
    m_delay = 1;
    m_bufferSize = static_cast<int>(m_delay * m_sampleRate);
    m_frameHistory.resize(m_bufferSize * m_channels, 0.0);
    Reset();
}

void CChorus::Process(const double* frameIn, double* frameOut, const double& time) {
    const int delay = static_cast<int>(m_delay * m_sampleRate + 0.5);
    m_phase += m_frequency * m_samplePeriod;

    for (size_t c = 0; c < m_channels; ++c) {
        const double waveform = m_amplitude * sin((m_phase - c * m_balanceOffset) * 2 * M_PI);
        m_frameHistory[m_bufferIndex * m_channels + c] = frameIn[c] * waveform;
    }

    for (size_t c = 0; c < m_channels; ++c) {
        const double input = frameIn[c];
        if (delay * m_channels <= m_frameHistory.size()) {
            frameOut[c] = input * (1.0 - m_wetness) + m_frameHistory[(m_bufferIndex + delay) % m_bufferSize * m_channels + c] * m_wetness;
        }
        else {
            frameOut[c] = input;
        }
    }
    m_bufferIndex = (m_bufferIndex + 1) % m_bufferSize;
}

void CChorus::XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value) {
    try {
        if (name == L"rate") {
            value.ChangeType(VT_R8);
            m_frequency = value.dblVal;
        }
        else if (name == L"amount") {
            value.ChangeType(VT_R8);
            m_amplitude = value.dblVal;
        }
        else if (name == L"phase") {
            value.ChangeType(VT_R8);
            m_phase = value.dblVal;
        }
        else if (name == L"channelOffset" || name == L"offset") {
            value.ChangeType(VT_R8);
            m_balanceOffset = value.dblVal;
        }
        else if (name == L"mix" || name == L"wetness") {
            value.ChangeType(VT_R8);
            m_wetness = value.dblVal;
        }
        else if (name == L"delay") {
            value.ChangeType(VT_R8);
            m_delay = value.dblVal;
            m_bufferSize = static_cast<int>(m_delay * m_sampleRate);
            m_frameHistory.resize(m_bufferSize * m_channels, 0.0);
        }
    }
    catch (...) {
        // Handle errors
    }
}

void CChorus::Reset() {
    m_bufferIndex = 0;
    std::fill(m_frameHistory.begin(), m_frameHistory.end(), 0.0);
}
