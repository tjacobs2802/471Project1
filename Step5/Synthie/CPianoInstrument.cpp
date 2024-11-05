#include "stdafx.h"
#include "CPianoInstrument.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>


CPianoInstrument::CPianoInstrument(double bpm): CInstrument(bpm), m_sampleIndex(0), m_time(0) {

}

CPianoInstrument::~CPianoInstrument() {
}

void CPianoInstrument::Start() {
    m_sampleIndex = 0;
    m_time = 0;

	m_ar.SetSource(&m_sinewave);
	m_ar.SetSampleRate(GetSampleRate());
	m_ar.Start();
}

bool CPianoInstrument::Generate() {
    if (m_sampleIndex < m_currentSample.size()) {
        m_frame[0] = m_currentSample[m_sampleIndex]; // Assuming mono samples
        m_frame[1] = m_currentSample[m_sampleIndex];
        m_sampleIndex++;
        m_time += GetSamplePeriod();
        return true;
    }
    else if (m_sampleIndex < m_currentSample.size() + m_pedalNoiseSample.size()) {
        size_t pedalIndex = m_sampleIndex - m_currentSample.size();
        m_frame[0] = m_pedalNoiseSample[pedalIndex]; // Assuming mono samples
        m_frame[1] = m_pedalNoiseSample[pedalIndex];
        m_sampleIndex++;
        m_time += GetSamplePeriod();
        return true;
    }
    return false;
}

void CPianoInstrument::SetNote(CNote* note) {
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);

    for (int i = 0; i < len; i++) {
        CComPtr<IXMLDOMNode> attrib;
        attributes->get_item(i, &attrib);

        // Get the attribute name and value
        CComBSTR name;
        attrib->get_nodeName(&name);

        CComVariant value;
        attrib->get_nodeValue(&value);

        if (name == "duration") {
            value.ChangeType(VT_R8);  // Convert to double
            m_duration = value.dblVal * (NUM_SECS_IN_MINUTE / m_bpm);  // Set duration in seconds
        }
        else if (name == "piano") {  // Check for piano type
			std::wstring pianoName = value.bstrVal;
            LoadSample(pianoName);
        }
        else if (name == "pedal") {  // Check for pedal noise
            std::wstring pedalNoiseName = value.bstrVal;
            LoadSample(pedalNoiseName, true);
        }
        
		m_sampleIndex = 0;  // Reset the sample index
    }
}

// Function to load a sample file into the m_samples map
void CPianoInstrument::LoadSample(const std::wstring& pianoName, bool isPedalNoise) {
    // Construct the file path from the drum name
    std::wstring path = L"../media/CompletePiano/" + pianoName + L".wav";

    std::ifstream file(path, std::ios::binary);
    if (!file) {
        std::runtime_error("Failed to open file\n");
    }

    // Validate WAV header
    char riff[4];
    file.read(riff, 4);
    if (std::string(riff, 4) != "RIFF") {
        std::runtime_error("Invalid WAV file\n");
    }

    file.seekg(40, std::ios::beg);
    uint32_t dataSize = 0;
    file.read(reinterpret_cast<char*>(&dataSize), sizeof(dataSize));

    size_t numFrames = dataSize / (sizeof(int16_t) * 2);  // Assuming stereo
    std::vector<double> samples(numFrames * 2);  // Store as double

    // Read each frame, convert to double, and normalize
    int ndx = 0;
    for (size_t i = 0; i < numFrames; ++i) {
        int16_t frame[2];  // Stereo frame
        file.read(reinterpret_cast<char*>(frame), sizeof(frame));

        // Normalize to the range [-1.0, 1.0]
        samples[ndx++] = frame[0] / 32768.0;  // Left
        samples[ndx++] = frame[1] / 32768.0;  // Right
    }

    if (isPedalNoise) {
        m_pedalNoiseSample = samples;
    }
    else {
        m_currentSample = samples;
    }
}
