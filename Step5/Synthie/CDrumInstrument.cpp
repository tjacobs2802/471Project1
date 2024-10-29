#include "stdafx.h"
#include "CDrumInstrument.h"
#include <fstream>
#include <stdexcept>
#include <iostream>  // For debugging output

CDrumInstrument::CDrumInstrument(double bpm)
    : CInstrument(bpm), m_sampleIndex(0), m_time(0) {
    // Load drum samples (example: kick = 1, snare = 2)
    LoadDrumSample(1, "../media/CompleteDrum/kick-big.wav");
    LoadDrumSample(2, "../media/CompleteDrum/snare-808.wav");
}

CDrumInstrument::~CDrumInstrument() {}

void CDrumInstrument::Start() {
    m_sampleIndex = 0;
    m_time = 0;
}

bool CDrumInstrument::Generate() {
    if (m_sampleIndex < m_currentSample.size()) {
        // Output the current sample to both audio channels
        m_frame[0] = m_currentSample[m_sampleIndex];  // Left channel
        m_frame[1] = m_currentSample[m_sampleIndex];  // Right channel
        ++m_sampleIndex;  // Move to the next sample
        m_time += GetSamplePeriod();  // Update time

        return true;  // Continue generating
    }
    return false;  // Stop generating when the sample finishes
}

void CDrumInstrument::SetNote(CNote* note) {
    // Get the list of attributes from the XML node
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);

    // Loop through the attributes to extract the drum type and duration
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
        else if (name == "drum") {  // Check for drum type
            value.ChangeType(VT_I4);  // Convert to integer
            int drumType = value.intVal;  // Get the drum type as an integer

            // Check if the drum type exists in the sample map
            if (m_drumSamples.find(drumType) != m_drumSamples.end()) {
                // Set the current sample based on the drum type
                m_currentSample = m_drumSamples[drumType];
                m_sampleIndex = 0;  // Reset sample index to start from the beginning
            }
            else {
                // Handle invalid drum type
                std::cerr << "Warning: Invalid drum type: " << drumType << std::endl;
                throw std::runtime_error("Invalid drum type: " + std::to_string(drumType));
            }
        }
    }
}

void CDrumInstrument::LoadDrumSample(int drumType, const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    // Read WAV header (ensure it’s a valid RIFF/WAV file)
    char riff[4];
    file.read(riff, 4);
    if (std::string(riff, 4) != "RIFF") {
        throw std::runtime_error("Invalid WAV file: " + filePath);
    }

    file.seekg(40, std::ios::beg);  // Skip to the data chunk size
    uint32_t dataSize = 0;
    file.read(reinterpret_cast<char*>(&dataSize), sizeof(dataSize));

    if (dataSize == 0) {
        throw std::runtime_error("Invalid data size in WAV file: " + filePath);
    }

    // Read audio data into a temporary buffer
    std::vector<int16_t> samples(dataSize / sizeof(int16_t));
    file.read(reinterpret_cast<char*>(samples.data()), dataSize);

    if (file.gcount() != dataSize) {
        throw std::runtime_error("Failed to read the complete WAV data.");
    }

    // Convert samples to double and store them safely in m_drumSamples
    std::vector<double> doubleSamples(samples.size());
    for (size_t i = 0; i < samples.size(); ++i) {
        doubleSamples[i] = samples[i] / 32768.0;  // Normalize 16-bit data to [-1, 1]
    }

    m_drumSamples[drumType] = std::move(doubleSamples);
}