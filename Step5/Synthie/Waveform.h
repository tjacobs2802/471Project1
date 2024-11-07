#pragma once
#include "AudioNode.h"
#include <vector>
#include <string>

/**
 * CWaveform is responsible for managing waveform synthesis, including
 * loading audio samples, handling playback with looping, and applying
 * effects like glissando. Inherits from CAudioNode.
 */
class CWaveform : public CAudioNode
{
public:
    CWaveform();

    // Initializes waveform parameters for playback
    void Start();

    // Converts note names and octave numbers into sample IDs for lookup
    int GetSample(std::wstring note);

    // Loads audio sample into a lookup table for quick access during synthesis
    void LoadSamp(int noteId, int type);

	// Loads wavetable sample
    void LoadWavetableSample(int noteId, const std::wstring& path);


    // Generates audio samples for the current frame
    virtual bool Generate();

    // Setter and getter functions for time and duration
    void SetTime(double t) { m_time = t; }
    double Time() { return m_time; }
    void SetDuration(double d) { m_duration = d; }
    double Duration() { return m_duration; }

    // Setter for next note
    void SetNextNote(int note) { m_nextNote = note; }

    // Getters for attack, release, and loop points for waveform control
    double Attack() { return m_attack; }
    double Release() { return m_release; }
    double LoopStart() { return m_loopStart; }
    double LoopEnd() { return m_loopEnd; }

private:
    // Synthesis parameters for timing, amplitude, and looping control
    double m_time;                 // Current playback time in seconds
    double m_amp;                  // Amplitude of the waveform
    double m_duration;             // Duration of the note to play
    double m_attack = 0.01;        // Attack duration (seconds)
    double m_release = 0.03;       // Release duration (seconds)
    double m_loopStart = 0.055;    // Start of loop section (seconds)
    double m_loopEnd = 0.1;        // End of loop section (seconds)
    int m_currentNote;              // Current note ID to play
    int m_nextNote;                // Next note ID for glissando effect
    int m_frameIndex = 0;          // Frame index within the sample
    int m_loopNum;                 // Counter for number of loop repetitions

    // List of file paths for loading audio samples
    std::vector<std::wstring> m_fileList;

    // Lookup table of audio samples, each note ID maps to its sample data
    std::vector<std::vector<short>> m_waveFormCache;

    // List of musical notes for sample ID calculation and file generation
    std::vector<std::wstring> m_noteList{ L"C", L"Db", L"D", L"Eb", L"E", L"F", L"Gb", L"G", L"Ab", L"A", L"Bb", L"B" };
    std::vector<std::wstring> m_noteListSharp{ L"C", L"C#", L"D", L"D#", L"E", L"F", L"F#", L"G", L"G#", L"A", L"A#", L"B" };

 
};
