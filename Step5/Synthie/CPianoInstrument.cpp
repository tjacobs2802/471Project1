#include "stdafx.h"
#include "CPianoInstrument.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>


CPianoInstrument::CPianoInstrument(double bpm): CInstrument(bpm), m_sampleIndex(0), m_time(0) {
    // Load samples here
    // Example: LoadSample(60, "path/to/sample.wav"); // Load middle C
    
	//CPianoInstrument::LoadSample(1, "../media/CompletePiano/A0#l.wav");
	//CPianoInstrument::LoadSample(2, "../media/CompletePiano/A0#s.wav");
	//CPianoInstrument::LoadSample(3, "../media/CompletePiano/A0l.wav");
	//CPianoInstrument::LoadSample(4, "../media/CompletePiano/A0s.wav");
	//CPianoInstrument::LoadSample(5, "../media/CompletePiano/A1#l.wav");
	//CPianoInstrument::LoadSample(6, "../media/CompletePiano/A1#s.wav");
	//CPianoInstrument::LoadSample(7, "../media/CompletePiano/A1l.wav");
	//CPianoInstrument::LoadSample(8, "../media/CompletePiano/A1s.wav");
	//CPianoInstrument::LoadSample(9, "../media/CompletePiano/A2#l.wav");
	CPianoInstrument::LoadSample(10, "../media/CompletePiano/A2#s.wav");
	//CPianoInstrument::LoadSample(11, "../media/CompletePiano/A2l.wav");
	//CPianoInstrument::LoadSample(12, "../media/CompletePiano/A2s.wav");
	//CPianoInstrument::LoadSample(13, "../media/CompletePiano/A3#l.wav");
	CPianoInstrument::LoadSample(14, "../media/CompletePiano/A3#s.wav");
	CPianoInstrument::LoadSample(15, "../media/CompletePiano/A3l.wav");
	CPianoInstrument::LoadSample(16, "../media/CompletePiano/A3s.wav");
	CPianoInstrument::LoadSample(17, "../media/CompletePiano/A4#l.wav");
	CPianoInstrument::LoadSample(18, "../media/CompletePiano/A4#s.wav");
	CPianoInstrument::LoadSample(19, "../media/CompletePiano/A4l.wav");
	CPianoInstrument::LoadSample(20, "../media/CompletePiano/A4s.wav");
	CPianoInstrument::LoadSample(21, "../media/CompletePiano/A5#l.wav");
	CPianoInstrument::LoadSample(22, "../media/CompletePiano/A5#s.wav");
	//CPianoInstrument::LoadSample(23, "../media/CompletePiano/A5l.wav");
	//CPianoInstrument::LoadSample(24, "../media/CompletePiano/A5s.wav");
	CPianoInstrument::LoadSample(25, "../media/CompletePiano/A6#l.wav");
	//CPianoInstrument::LoadSample(26, "../media/CompletePiano/A6#s.wav");
	//CPianoInstrument::LoadSample(27, "../media/CompletePiano/A6l.wav");
	//CPianoInstrument::LoadSample(28, "../media/CompletePiano/A6s.wav");
	//CPianoInstrument::LoadSample(29, "../media/CompletePiano/A7#l.wav");
	//CPianoInstrument::LoadSample(30, "../media/CompletePiano/A7#s.wav");
	//CPianoInstrument::LoadSample(31, "../media/CompletePiano/A7l.wav");
	//CPianoInstrument::LoadSample(32, "../media/CompletePiano/A7s.wav");
    CPianoInstrument::LoadSample(35, "../media/CompletePiano/B0l.wav");
 //   CPianoInstrument::LoadSample(36, "../media/CompletePiano/B0s.wav");
 //   CPianoInstrument::LoadSample(39, "../media/CompletePiano/B1l.wav");
 //   CPianoInstrument::LoadSample(40, "../media/CompletePiano/B1s.wav");
 //   CPianoInstrument::LoadSample(43, "../media/CompletePiano/B2l.wav");
 //   CPianoInstrument::LoadSample(44, "../media/CompletePiano/B2s.wav");
 //   CPianoInstrument::LoadSample(47, "../media/CompletePiano/B3l.wav");
 //   CPianoInstrument::LoadSample(48, "../media/CompletePiano/B3s.wav");
    CPianoInstrument::LoadSample(51, "../media/CompletePiano/B4l.wav");
 //   CPianoInstrument::LoadSample(52, "../media/CompletePiano/B4s.wav");
 //   CPianoInstrument::LoadSample(55, "../media/CompletePiano/B5l.wav");
 //   CPianoInstrument::LoadSample(56, "../media/CompletePiano/B5s.wav");
 //   CPianoInstrument::LoadSample(59, "../media/CompletePiano/B6l.wav");
 //   CPianoInstrument::LoadSample(60, "../media/CompletePiano/B6s.wav");
 //   CPianoInstrument::LoadSample(64, "../media/CompletePiano/B7l.wav");
    CPianoInstrument::LoadSample(65, "../media/CompletePiano/B7s.wav");
    CPianoInstrument::LoadSample(70, "../media/CompletePiano/C1#l.wav");
    CPianoInstrument::LoadSample(71, "../media/CompletePiano/C1#s.wav");
    CPianoInstrument::LoadSample(72, "../media/CompletePiano/C1l.wav");
    CPianoInstrument::LoadSample(73, "../media/CompletePiano/C1s.wav");
    CPianoInstrument::LoadSample(74, "../media/CompletePiano/C2#l.wav");
    CPianoInstrument::LoadSample(75, "../media/CompletePiano/C2#s.wav");
    CPianoInstrument::LoadSample(76, "../media/CompletePiano/C2l.wav");
    CPianoInstrument::LoadSample(77, "../media/CompletePiano/C2s.wav");
    CPianoInstrument::LoadSample(78, "../media/CompletePiano/C3#l.wav");
    CPianoInstrument::LoadSample(79, "../media/CompletePiano/C3#s.wav");
    CPianoInstrument::LoadSample(80, "../media/CompletePiano/C3l.wav");
    CPianoInstrument::LoadSample(81, "../media/CompletePiano/C3s.wav");
    CPianoInstrument::LoadSample(82, "../media/CompletePiano/C4#l.wav");
    CPianoInstrument::LoadSample(83, "../media/CompletePiano/C4#s.wav");
    CPianoInstrument::LoadSample(84, "../media/CompletePiano/C4l.wav");
    CPianoInstrument::LoadSample(85, "../media/CompletePiano/C4s.wav");
    CPianoInstrument::LoadSample(86, "../media/CompletePiano/C5#l.wav");
    CPianoInstrument::LoadSample(87, "../media/CompletePiano/C5#s.wav");
    CPianoInstrument::LoadSample(88, "../media/CompletePiano/C5l.wav");
    CPianoInstrument::LoadSample(89, "../media/CompletePiano/C5s.wav");
    CPianoInstrument::LoadSample(90, "../media/CompletePiano/C6#l.wav");
    CPianoInstrument::LoadSample(91, "../media/CompletePiano/C6#s.wav");
    CPianoInstrument::LoadSample(92, "../media/CompletePiano/C6l.wav");
    CPianoInstrument::LoadSample(93, "../media/CompletePiano/C6s.wav");
    CPianoInstrument::LoadSample(94, "../media/CompletePiano/C7#l.wav");
    CPianoInstrument::LoadSample(95, "../media/CompletePiano/C7#s.wav");
    CPianoInstrument::LoadSample(96, "../media/CompletePiano/C7l.wav");
    CPianoInstrument::LoadSample(97, "../media/CompletePiano/C7s.wav");
    //CPianoInstrument::LoadSample(102, "../media/CompletePiano/D1#l.wav");
    //CPianoInstrument::LoadSample(103, "../media/CompletePiano/D1#s.wav");
    //CPianoInstrument::LoadSample(104, "../media/CompletePiano/D1l.wav");
    //CPianoInstrument::LoadSample(105, "../media/CompletePiano/D1s.wav");
    //CPianoInstrument::LoadSample(106, "../media/CompletePiano/D2#l.wav");
    //CPianoInstrument::LoadSample(107, "../media/CompletePiano/D2#s.wav");
    //CPianoInstrument::LoadSample(108, "../media/CompletePiano/D2l.wav");
    //CPianoInstrument::LoadSample(109, "../media/CompletePiano/D2s.wav");
    CPianoInstrument::LoadSample(110, "../media/CompletePiano/D3#l.wav");
    CPianoInstrument::LoadSample(111, "../media/CompletePiano/D3#s.wav");
    //CPianoInstrument::LoadSample(112, "../media/CompletePiano/D3l.wav");
    //CPianoInstrument::LoadSample(113, "../media/CompletePiano/D3s.wav");
    //CPianoInstrument::LoadSample(114, "../media/CompletePiano/D4#l.wav");
    //CPianoInstrument::LoadSample(115, "../media/CompletePiano/D4#s.wav");
    //CPianoInstrument::LoadSample(116, "../media/CompletePiano/D4l.wav");
    //CPianoInstrument::LoadSample(117, "../media/CompletePiano/D4s.wav");
    //CPianoInstrument::LoadSample(118, "../media/CompletePiano/D5#l.wav");
    //CPianoInstrument::LoadSample(119, "../media/CompletePiano/D5#s.wav");
    CPianoInstrument::LoadSample(120, "../media/CompletePiano/D5l.wav");
    CPianoInstrument::LoadSample(121, "../media/CompletePiano/D5s.wav");
    CPianoInstrument::LoadSample(122, "../media/CompletePiano/D6#l.wav");
    CPianoInstrument::LoadSample(123, "../media/CompletePiano/D6#s.wav");
    CPianoInstrument::LoadSample(124, "../media/CompletePiano/D6l.wav");
    CPianoInstrument::LoadSample(125, "../media/CompletePiano/D6s.wav");
    CPianoInstrument::LoadSample(126, "../media/CompletePiano/D7#l.wav");
    CPianoInstrument::LoadSample(127, "../media/CompletePiano/D7#s.wav");
    CPianoInstrument::LoadSample(128, "../media/CompletePiano/D7l.wav");
    CPianoInstrument::LoadSample(129, "../media/CompletePiano/D7s.wav");
    CPianoInstrument::LoadSample(136, "../media/CompletePiano/E1l.wav");
    CPianoInstrument::LoadSample(137, "../media/CompletePiano/E1s.wav");
    CPianoInstrument::LoadSample(140, "../media/CompletePiano/E2l.wav");
    //CPianoInstrument::LoadSample(141, "../media/CompletePiano/E2s.wav");
    //CPianoInstrument::LoadSample(144, "../media/CompletePiano/E3l.wav");
    //CPianoInstrument::LoadSample(145, "../media/CompletePiano/E3s.wav");
    //CPianoInstrument::LoadSample(148, "../media/CompletePiano/E4l.wav");
    //CPianoInstrument::LoadSample(149, "../media/CompletePiano/E4s.wav");
    CPianoInstrument::LoadSample(152, "../media/CompletePiano/E5l.wav");
    //CPianoInstrument::LoadSample(153, "../media/CompletePiano/E5s.wav");
    //CPianoInstrument::LoadSample(156, "../media/CompletePiano/E6l.wav");
    //CPianoInstrument::LoadSample(157, "../media/CompletePiano/E6s.wav");
    CPianoInstrument::LoadSample(160, "../media/CompletePiano/E7l.wav");
    //CPianoInstrument::LoadSample(161, "../media/CompletePiano/E7s.wav");
    //CPianoInstrument::LoadSample(167, "../media/CompletePiano/F1#l.wav");
    //CPianoInstrument::LoadSample(168, "../media/CompletePiano/F1#s.wav");
    //CPianoInstrument::LoadSample(169, "../media/CompletePiano/F1l.wav");
    //CPianoInstrument::LoadSample(170, "../media/CompletePiano/F1s.wav");
    //CPianoInstrument::LoadSample(171, "../media/CompletePiano/F2#l.wav");
    //CPianoInstrument::LoadSample(172, "../media/CompletePiano/F2#s.wav");
    //CPianoInstrument::LoadSample(173, "../media/CompletePiano/F2l.wav");
    CPianoInstrument::LoadSample(174, "../media/CompletePiano/F2s.wav");
    CPianoInstrument::LoadSample(175, "../media/CompletePiano/F3#l.wav");
    CPianoInstrument::LoadSample(176, "../media/CompletePiano/F3#s.wav");
    CPianoInstrument::LoadSample(177, "../media/CompletePiano/F3l.wav");
    CPianoInstrument::LoadSample(178, "../media/CompletePiano/F3s.wav");
    CPianoInstrument::LoadSample(179, "../media/CompletePiano/F4#l.wav");
    CPianoInstrument::LoadSample(180, "../media/CompletePiano/F4#s.wav");
    CPianoInstrument::LoadSample(181, "../media/CompletePiano/F4l.wav");
    CPianoInstrument::LoadSample(182, "../media/CompletePiano/F4s.wav");
    //CPianoInstrument::LoadSample(183, "../media/CompletePiano/F5#l.wav");
    //CPianoInstrument::LoadSample(184, "../media/CompletePiano/F5#s.wav");
    //CPianoInstrument::LoadSample(185, "../media/CompletePiano/F5l.wav");
    //CPianoInstrument::LoadSample(186, "../media/CompletePiano/F5s.wav");
    //CPianoInstrument::LoadSample(187, "../media/CompletePiano/F6#l.wav");
    //CPianoInstrument::LoadSample(188, "../media/CompletePiano/F6#s.wav");
    //CPianoInstrument::LoadSample(189, "../media/CompletePiano/F6l.wav");
    //CPianoInstrument::LoadSample(190, "../media/CompletePiano/F6s.wav");
    //CPianoInstrument::LoadSample(191, "../media/CompletePiano/F7#l.wav");
    //CPianoInstrument::LoadSample(192, "../media/CompletePiano/F7#s.wav");
    //CPianoInstrument::LoadSample(193, "../media/CompletePiano/F7l.wav");
    //CPianoInstrument::LoadSample(194, "../media/CompletePiano/F7s.wav");
    //CPianoInstrument::LoadSample(199, "../media/CompletePiano/G1#l.wav");
    //CPianoInstrument::LoadSample(200, "../media/CompletePiano/G1#s.wav");
    //CPianoInstrument::LoadSample(201, "../media/CompletePiano/G1l.wav");
    //CPianoInstrument::LoadSample(202, "../media/CompletePiano/G1s.wav");
    //CPianoInstrument::LoadSample(203, "../media/CompletePiano/G2#l.wav");
    //CPianoInstrument::LoadSample(204, "../media/CompletePiano/G2#s.wav");
    //CPianoInstrument::LoadSample(205, "../media/CompletePiano/G2l.wav");
    //CPianoInstrument::LoadSample(206, "../media/CompletePiano/G2s.wav");
    //CPianoInstrument::LoadSample(207, "../media/CompletePiano/G3#l.wav");
    //CPianoInstrument::LoadSample(208, "../media/CompletePiano/G3#s.wav");
    //CPianoInstrument::LoadSample(209, "../media/CompletePiano/G3l.wav");
    //CPianoInstrument::LoadSample(210, "../media/CompletePiano/G3s.wav");
    //CPianoInstrument::LoadSample(211, "../media/CompletePiano/G4#l.wav");
    //CPianoInstrument::LoadSample(212, "../media/CompletePiano/G4#s.wav");
    //CPianoInstrument::LoadSample(213, "../media/CompletePiano/G4l.wav");
    //CPianoInstrument::LoadSample(214, "../media/CompletePiano/G4s.wav");
    //CPianoInstrument::LoadSample(215, "../media/CompletePiano/G5#l.wav");
    CPianoInstrument::LoadSample(216, "../media/CompletePiano/G5#s.wav");
    CPianoInstrument::LoadSample(217, "../media/CompletePiano/G5l.wav");
    CPianoInstrument::LoadSample(218, "../media/CompletePiano/G5s.wav");
    CPianoInstrument::LoadSample(219, "../media/CompletePiano/G6#l.wav");
    CPianoInstrument::LoadSample(220, "../media/CompletePiano/G6#s.wav");
    CPianoInstrument::LoadSample(221, "../media/CompletePiano/G6l.wav");
    CPianoInstrument::LoadSample(222, "../media/CompletePiano/G6s.wav");
    CPianoInstrument::LoadSample(223, "../media/CompletePiano/G7#l.wav");
    CPianoInstrument::LoadSample(224, "../media/CompletePiano/G7#s.wav");
    CPianoInstrument::LoadSample(225, "../media/CompletePiano/G7l.wav");
    CPianoInstrument::LoadSample(226, "../media/CompletePiano/G7s.wav");

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
        else if (name == "piano") {  // Check for piano type
            value.ChangeType(VT_I4);  // Convert to integer
            int pianoType = value.intVal;

            // Check if the piano type exists in the sample map
            if (m_samples.find(pianoType) != m_samples.end()) {
                // Set the current sample based on the piano type
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
void CPianoInstrument::LoadSample(int pianoType, const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    char riff[4];
    file.read(riff, 4);
    if (std::string(riff, 4) != "RIFF") {
        std::cerr << "Read header: " << std::string(riff, 4) << std::endl;
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

    m_samples[pianoType] = std::move(doubleSamples);
}