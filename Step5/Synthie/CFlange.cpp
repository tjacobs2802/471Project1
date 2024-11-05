#include "stdafx.h"
#include "CFlange.h"
#include <cmath>
#include <deque>

#ifndef M_PI 
#define M_PI 3.14159265358979323846 
#endif

std::deque<double> m_frameHistory;

CFlange::CFlange(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod)
{
	m_phase = 0;
	m_frequency = 0.25;
	m_amplitude = 1;
	m_feedback = 0.5;
	m_wetness = 0.8;
	Reset();
}

CFlange::~CFlange()
{

}

void CFlange::Process(const double* frameIn, double* frameOut, const double& time)
{
	const double modulation = sin(m_phase * 2 * M_PI);
	m_phase += m_frequency * m_samplePeriod;
	if (m_phase > 2 * M_PI) m_phase -= 2 * M_PI;

	int delay = int((0.005 + m_amplitude * (modulation + 1)/2) * m_sampleRate);

	// Push current frame into history with feedback
	for (size_t i = 0; i < m_channels; i++)
	{
		double delayedSample = (m_frameHistory.size() > delay * m_channels)
			? m_frameHistory[m_frameHistory.size() - delay * m_channels]
			: 0;

		m_frameHistory.push_back(frameIn[i] + delayedSample * m_feedback);

		if (m_frameHistory.size() > delay * m_channels)
			m_frameHistory.pop_front();

		// Mix wet and dry signals
		frameOut[i] = (1 - m_wetness) * frameIn[i] + m_wetness * delayedSample;
	}
}

void CFlange::XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value)
{
	if (name == L"rate")
	{
		value.ChangeType(VT_R8);
		m_frequency = value.dblVal;
	}
	else if (name == L"amount")
	{
		value.ChangeType(VT_R8);
		m_amplitude = value.dblVal;
	}
	else if (name == L"phase")
	{
		value.ChangeType(VT_R8);
		m_phase = value.dblVal;
	}
	else if (name == L"feedback")
	{
		value.ChangeType(VT_R8);
		m_feedback = value.dblVal;
	}
	else if (name == L"mix" || name == L"wetness")
	{
		value.ChangeType(VT_R8);
		m_wetness = value.dblVal;
	}
}

void CFlange::Reset()
{
	m_frameHistory.clear();
	m_delayIndex = 0;
	m_bufferIndex = 0;

}
