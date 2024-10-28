#include "stdafx.h"
#include "EchoEffect.h"

double GetParameterFromNode(IXMLDOMNode* node, const std::wstring& paramName);

EchoEffect::EchoEffect() : m_wet(0.5), m_dry(0.5), m_delay(1.0), m_writeIndex(0) {
    const double sampleRate = 44100.0; 
    m_delaySamples = static_cast<int>(m_delay * sampleRate);

    m_delayBuffer.resize(m_delaySamples, 0.0);
}

void EchoEffect::SetNote(const CNote* note) {
    if (note) { // Check if note is not null
        IXMLDOMNode* xmlNode = note->Node(); // Access the node
        if (xmlNode) { // Ensure xmlNode is valid
            m_wet = GetParameterFromNode(xmlNode, L"wet");
            m_dry = GetParameterFromNode(xmlNode, L"dry");
            m_delay = GetParameterFromNode(xmlNode, L"delay");
        }
    }
}

void EchoEffect::Process(double* frameIn, double* frameOut) {
    // Initialize output frame
    for (int c = 0; c < 2; c++) {
        frameOut[c] = 0.0; // Zero out the output frame
    }

    // Read the delayed signal from the buffer
    double delayedSignal = m_delayBuffer[m_writeIndex];

    // Apply the echo effect to the input frame
    for (int c = 0; c < 2; c++) {
        frameOut[c] = m_dry * frameIn[c] + m_wet * delayedSignal; // Mix dry input and wet delayed signal
    }

    // Update the delay buffer with the new sample
    m_delayBuffer[m_writeIndex] = frameIn[0]; // Assuming mono input for this example
    m_writeIndex = (m_writeIndex + 1) % m_delaySamples; // Circular buffer logic
}

double GetParameterFromNode(IXMLDOMNode* node, const std::wstring& paramName) {
    BSTR bstrValue;

    IXMLDOMNode* paramNode; 

    if (paramNode) {
        paramNode->get_text(&bstrValue); 
        double value = std::wcstod(bstrValue, nullptr); 
        SysFreeString(bstrValue); 
        return value;
    }

    return 0.0;
}
