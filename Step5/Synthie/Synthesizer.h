using namespace std;
#pragma once
#include <list>
#include <string>
#include <vector>
#include <memory>
#include "msxml2.h"
#include "Instrument.h"
#include "Note.h"
#include "CEffect.h"
#include <map>

class CSynthesizer
{
public:
	CSynthesizer();
	virtual ~CSynthesizer();
public:
	//! Number of audio channels
	int GetNumChannels() { return m_channels; }

	//! Sample rate in samples per second
	double GetSampleRate() { return m_sampleRate; }

	//! Sample period in seconds (1/samplerate)
	double GetSamplePeriod() { return m_samplePeriod; }

	//! Beats per minute 
	double GetBeatsPerMinute() { return m_bpm; }

	//! Set the number of channels
	void SetNumChannels(int n) { m_channels = n; }

	//! Set the sample rate
	void SetSampleRate(double s) { m_sampleRate = s;  m_samplePeriod = 1.0 / s; }

	void Clear();
	void OpenScore(CString & );
	void XmlLoadScore(IXMLDOMNode * xml);
	void XmlLoadInstrument(IXMLDOMNode * xml);
	void XmlLoadEffectList(IXMLDOMNode* xml);
	void AddEffect(std::shared_ptr<CEffect> effect);
	void XmlLoadNote(IXMLDOMNode * xml, std::wstring & instrument, std::wstring& effect);
private:
	int		m_channels;
	double	m_sampleRate;
	double	m_samplePeriod;
	double  m_bpm;                  //!< Beats per minute
	int     m_beatspermeasure;  //!< Beats per measure
	double  m_secperbeat;        //!< Seconds per beat
	int m_currentNote;          //!< The current note we are playing
	int m_measure;              //!< The current measure
	double m_beat;              //!< The current beat within the measure


	// JULIA- TRYING SOMETHING BELOW:

	std::vector<std::shared_ptr<CEffect>> m_effects;
	std::map<std::wstring, std::shared_ptr<CEffect>> m_effectCatalog;

	// 

	std::list<CInstrument *>  m_instruments;
	std::vector<CNote> m_notes;
public:
	void Start();
	bool Generate(double*);
private:
	double m_time;
public:
	double GetTime();
};

