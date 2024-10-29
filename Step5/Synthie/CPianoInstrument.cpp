#include "stdafx.h"
#include "CPianoInstrument.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>


CPianoInstrument::CPianoInstrument(double bpm) : CInstrument(bpm), m_sampleIndex(0), m_time(0) {
    // Load samples here
    // Example: LoadSample(60, "path/to/sample.wav"); // Load middle C
	CPianoInstrument::LoadSample(1, "../media/CompletePiano/C4s.wav");
}

CPianoInstrument::~CPianoInstrument() {
}

void CPianoInstrument::Start() {
    m_sampleIndex = 0;
    m_time = 0;
}

bool CPianoInstrument::Generate() {
    if (m_sampleIndex < m_currentSample.size()) {
        m_frame[0] = m_currentSample[m_sampleIndex]; // Assuming mono samples
        m_frame[1] = m_currentSample[m_sampleIndex];
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
        else if (name == "piano") {  // Check for drum type
            value.ChangeType(VT_I4);  // Convert to integer
            int pianoType = value.intVal;

            // Check if the drum type exists in the sample map
            if (m_samples.find(pianoType) != m_samples.end()) {
                // Set the current sample based on the drum type
                m_currentSample = m_samples[pianoType];
                m_sampleIndex = 0;  // Reset sample index to start from the beginning
            }
            else {
                // Handle invalid drum type
                std::cerr << "Warning: Invalid piano type: " << pianoType << std::endl;
                throw std::runtime_error("Invalid piano type: " + std::to_string(pianoType));
            }
        }
    }
}

// Function to load a sample file into the m_samples map
void CPianoInstrument::LoadSample(int midiNote, const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    // Read WAV header
    char riff[4];
    file.read(riff, 4);
    if (std::string(riff, 4) != "RIFF") {
        throw std::runtime_error("Invalid WAV file: " + filePath);
    }

    file.seekg(22, std::ios::beg); // Skip to number of channels
    uint16_t numChannels;
    file.read(reinterpret_cast<char*>(&numChannels), sizeof(numChannels));

    file.seekg(24, std::ios::beg); // Skip to sample rate
    uint32_t sampleRate;
    file.read(reinterpret_cast<char*>(&sampleRate), sizeof(sampleRate));

    file.seekg(34, std::ios::beg); // Skip to bits per sample
    uint16_t bitsPerSample;
    file.read(reinterpret_cast<char*>(&bitsPerSample), sizeof(bitsPerSample));

    file.seekg(40, std::ios::beg); // Skip to data size
    uint32_t dataSize;
    file.read(reinterpret_cast<char*>(&dataSize), sizeof(dataSize));

    std::vector<int16_t> samples(dataSize / (bitsPerSample / 8));
    file.read(reinterpret_cast<char*>(samples.data()), dataSize);

    // Convert samples to double and store in m_samples
    std::vector<double> doubleSamples(samples.size());
    for (size_t i = 0; i < samples.size(); ++i) {
        doubleSamples[i] = samples[i] / 32768.0; // Assuming 16-bit samples
    }

    m_samples[midiNote] = doubleSamples;
}