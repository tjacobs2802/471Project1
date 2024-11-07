#include "stdafx.h"
#include "Waveform.h"
#include "audio/DirSoundSource.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <random>
#include <vector>

using namespace std;

/**
 * Constructor initializes waveform and prepares file list.
 */
CWaveform::CWaveform()
{
    //GetFileList();

    //// Initialize the lookup table with empty vectors for each note ID.
    //for (int i = 0; i < m_fileList.size(); i++)
    //{
    //    m_waveFormCache.push_back(vector<short>());
    //}
    m_waveFormCache.resize(48);
}

/**
 * Start: Initializes waveform parameters for playback.
 */
void CWaveform::Start()
{
    m_time = 0;
    m_loopNum = 0;
    m_amp = 0.5;
}

/**
 * GetSample: Converts note name (e.g., "C4") to a unique sample ID.
 */
int CWaveform::GetSample(std::wstring note)
{
    int octave = note[note.size() - 1] - '0';
    wstring name = note.substr(0, note.size() - 1);
    int noteNum = (note.size() == 3 && note[1] == '#')
        ? distance(m_noteListSharp.begin(), find(m_noteListSharp.begin(), m_noteListSharp.end(), name))
        : distance(m_noteList.begin(), find(m_noteList.begin(), m_noteList.end(), name));
    return (12 * (octave - 1)) + noteNum;
}

/**
 * Generate: Generates the waveform by calculating the current sample.
 */
bool CWaveform::Generate()
{
    double glissDiff = ((m_nextNote >= 0) && (m_nextNote <= 47)) ? m_nextNote - m_currentNote : 0;
    double glissTime = m_time + ((LoopEnd() - LoopStart()) * (m_loopNum + 1));
    double glissCoeff = min(glissTime / m_duration, 1.0);

    int glissAmount = int(glissDiff * glissCoeff);
    int sample = m_currentNote + glissAmount;

    LoadSamp(sample, 2);
    int const i = m_frameIndex % m_waveFormCache[sample].size();
    m_frame[0] = double(m_waveFormCache[sample][i]) / 65535.0;
    m_frame[0] *= m_amp;
    m_frame[1] = m_frame[0];

    m_frameIndex++;
    m_time += GetSamplePeriod();

    // Loop back to loop start if within duration and loop end reached
    if ((m_time < (m_duration - Release())) && (m_time >= LoopEnd())) {
        m_time = LoopStart();
        m_frameIndex = int(LoopStart() / GetSamplePeriod());
        m_loopNum++;
    }
    return true;
}


void CWaveform::LoadWavetableSample(int noteId, const std::wstring& path)
{
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open wavetable file");
    }

    // Validate WAV header
    char riff[4];
    file.read(riff, 4);
    if (std::string(riff, 4) != "RIFF") {
        throw std::runtime_error("Invalid WAV file");
    }

    // Seek to the data size in the header
    file.seekg(40, std::ios::beg);
    uint32_t dataSize = 0;
    file.read(reinterpret_cast<char*>(&dataSize), sizeof(dataSize));

    // Calculate the number of frames (assuming stereo, 16-bit format)
    size_t numFrames = dataSize / (sizeof(int16_t) * 2);
    m_waveFormCache[noteId].resize(numFrames * 2);

    // Read each frame, convert to double, and normalize
    for (size_t i = 0; i < numFrames; ++i) {
        int16_t frame[2];  // Stereo frame
        file.read(reinterpret_cast<char*>(frame), sizeof(frame));

        // Store normalized samples in the cache
        m_waveFormCache[noteId][i * 2] = frame[0];  // Left
        m_waveFormCache[noteId][i * 2 + 1] = frame[1];  // Right
    }
    file.close();
}

void CWaveform::LoadSamp(int noteId, int type)
{
    if (noteId < 0 || noteId > 47 || !m_waveFormCache[noteId].empty())
        return;

    if (type == 0) {
        m_currentNote = noteId;
    }
    else if (type == 1) {
        m_nextNote = noteId;
    }
    std::wstring pathPrefix = L"../media/WaveSamples/";
    std::wstring noteName = m_noteList[noteId % 12] + std::to_wstring(noteId / 12 + 1); 
    std::wstring path = pathPrefix + L"wavetable_" + noteName + L".wav";

    LoadWavetableSample(noteId, path);
}
