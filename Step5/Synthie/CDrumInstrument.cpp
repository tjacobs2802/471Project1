#include "stdafx.h"
#include "CDrumInstrument.h"
#include <fstream>
#include <stdexcept>
#include <random>

CDrumInstrument::CDrumInstrument(double bpm)
    : CInstrument(bpm), m_sampleIndex(0), m_time(0) {
}

CDrumInstrument::~CDrumInstrument() {}

void CDrumInstrument::Start() {
    m_sampleIndex = 0;
    m_time = 0;

    m_ar.SetSource(&m_sinewave);
    m_ar.SetSampleRate(GetSampleRate());
    m_ar.Start();
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

void CDrumInstrument::GenerateSyntheticDrum() {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    m_currentSample.clear();
    size_t numFrames = static_cast<size_t>(GetSampleRate() * 0.5);

    for (size_t i = 0; i < numFrames; ++i) {
        double noise = distribution(generator);

        // Apply a quick decay to simulate a drum hit
        double decay = 1.0 - (static_cast<double>(i) / numFrames);
        double sample = noise * decay;

        m_currentSample.push_back(sample);
    }
}


void CDrumInstrument::SetNote(CNote* note) {
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);

    for (int i = 0; i < len; i++) {
        CComPtr<IXMLDOMNode> attrib;
        attributes->get_item(i, &attrib);

        CComBSTR name;
        attrib->get_nodeName(&name);

        CComVariant value;
        attrib->get_nodeValue(&value);

        if (name == "duration") {
            value.ChangeType(VT_R8);
            m_duration = value.dblVal * (NUM_SECS_IN_MINUTE / m_bpm);
        }
        else if (name == "drum") {
            std::wstring drumName = value.bstrVal;
            if (drumName != L"synthetic") {
                LoadDrumSample(drumName);
            }
            else {
                GenerateSyntheticDrum();    
            }
            
            m_sampleIndex = 0;
        }
    }
}

void CDrumInstrument::LoadDrumSample(const std::wstring& drumName) {
    // Construct the file path from the drum name
    std::wstring path = L"../media/CompleteDrum/" + drumName + L".wav";

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

    // Assign the loaded samples to m_currentSample
    m_currentSample =  samples;
}