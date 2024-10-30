#pragma once
#include "AudioNode.h"
#include <vector>
#include <string>

class CWaveform : public CAudioNode
{
public:
    CWaveform();

    void PrepareFileList();
    void LoadSampleIntoTable(int noteId, int type);
    int GetSampleIdFromNote(std::wstring note);
    void Start();
    virtual bool Generate();

    void SetTime(double t) { m_time = t; }
    double Time() { return m_time; }
    void SetDuration(double d) { m_duration = d; }
    void SetNextNote(int note) { m_nextNote = note; }
    double Duration() { return m_duration; }
    double Attack() { return m_attack; }
    double Release() { return m_release; }
    double LoopStart() { return m_loopStart; }
    double LoopEnd() { return m_loopEnd; }

private:
    double m_time;
    double m_amp;
    double m_duration;
    double m_attack = 0.01;
    double m_release = 0.03;
    double m_loopStart = 0.055;
    double m_loopEnd = 0.1;
    int m_noteToPlay;
    int m_nextNote;
    int m_frameIndex = 0;
    int m_loopNum;

    // List of notes
    std::vector<std::wstring> m_noteList{ L"C", L"Db", L"D", L"Eb", L"E", L"F", L"Gb", L"G", L"Ab", L"A", L"Bb", L"B" };
    std::vector<std::wstring> m_noteListAlt{ L"C", L"C#", L"D", L"D#", L"E", L"F", L"F#", L"G", L"G#", L"A", L"A#", L"B" };

    // File list
    std::vector<std::wstring> m_fileList;

    // Lookup table to be generated when the waveform is initialized
    std::vector<std::vector<short>> m_LookupTable;
};
