#include "stdafx.h"
#include "Waveform.h"
#include "audio/DirSoundSource.h"
#include <algorithm>

using namespace std;

/**
 * Constructor initializes waveform and prepares file list.
 */
CWaveform::CWaveform()
{
    GetFileList();

    // Initialize the lookup table with empty vectors for each note ID.
    for (int i = 0; i < m_fileList.size(); i++)
    {
        m_waveFormCache.push_back(vector<short>());
    }
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
 * GetFileList: Populates m_fileList with paths to WAV files.
 */
void CWaveform::GetFileList() {
    m_fileList.clear();
    std::wstring pathPrefix = L"../WaveSamples/";

    // Iterate through notes and octaves, constructing filenames
    for (int octave = 1; octave <= 4; ++octave) {
        for (const auto& note : m_noteList) {
            std::wstring filename = pathPrefix + L"wavetable_" + note + std::to_wstring(octave) + L".wav";
            int noteId = GetSample(note + std::to_wstring(octave));

            // Resize m_fileList to accommodate the new note ID, if needed
            if (noteId >= m_fileList.size()) {
                m_fileList.resize(noteId + 1);
            }

            // Store the filename at the position matching the note ID
            m_fileList[noteId] = filename;
        }
    }
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
 * LoadSamp: Loads audio sample data for a specified note ID into the lookup table.
 */
void CWaveform::LoadSamp(int noteId, int type)
{
    if ((noteId < 0) || (noteId > 47))
        return;

    // Skip loading if the sample has already been loaded
    if (m_waveFormCache[noteId].size() > 0)
        return;

    // Set member variables based on type parameter (current vs. next note)
    if (type == 0) {
        m_currentNote = noteId;
    } else if (type == 1) {
        m_nextNote = noteId;
    }

    CDirSoundSource audioin;
    if (!audioin.Open(m_fileList[noteId].c_str()))
        return;

    // Read each frame of audio and store it in the lookup table
    for (int i = 0; i < audioin.NumSampleFrames(); i++) {
        short audio[2];
        audioin.ReadFrame(audio);
        m_waveFormCache[noteId].push_back(audio[0]);
    }
    audioin.Close();
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
