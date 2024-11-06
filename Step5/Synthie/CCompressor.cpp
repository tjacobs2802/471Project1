#include "stdafx.h"
#include "CCompressor.h"


CCompressor::CCompressor(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod)
{
	m_currentVol = 0.0;
	m_stages = std::vector<Phase>(m_channels, Hold);
	m_times = std::vector<double>(m_channels, 0);
}

void CCompressor::Process(const double* frameIn, double* frameOut, const double& time)
{
	for (int c = 0; c < m_channels; c++)
	{
		double in = frameIn[c];
		double inAmp = abs(in);
		const int inSign = signbit(in) ? -1 : 1;
		double out = in;

		const double delta = in - (inSign * m_threshold);
		const double target = (inSign * m_threshold) + delta / m_ratio;

		Phase phase = m_stages.at(c);

		switch (phase)
		{
		case Hold:
		
			if (inAmp < m_threshold)
			{
				out = in;
			}
			else
			{
				m_times.at(c) = time;
				phase = Attack;
			}
			break;
		
		case Attack:
		
			if (inAmp < m_threshold) {
				m_times.at(c) = time;
				phase = Release;
			}
			else {
				const double fAtk = (time - m_times.at(c)) / m_attack;
				if (fAtk < 1) {
					out = in + (target - in) * fAtk;
				}
				else {
					out = target;
					phase = Active;
				}
			}
			break;
		
		case Active:
		
			if (inAmp > m_threshold) {
				out = target;
			}
			else {
				m_times.at(c) = time;
				phase = Release;
			}
			break;
		
		case Release:
		
			if (inAmp > m_threshold) {
				m_times.at(c) = time;
				phase = Attack;
			}
			else {
				const double fRls = (time - m_times.at(c)) / m_release;
				if (fRls < 1) {
					out = target + (in - target) * (1 - fRls);
				}
				else {
					out = in;
					phase = Hold;
				}
			}
			break;
		}
		
		frameOut[c] = out;
		m_stages.at(c) = phase;
	}
}

double CCompressor::GetDeltaGain(double frameIn)
{
	double deltaGain = 0.0;

	if (m_isUpwards)
	{
		if (frameIn < m_threshold)
		{
			deltaGain = (frameIn - m_threshold) / m_ratio;
		}
	}
	else if (!m_isUpwards && frameIn > m_threshold)
	{
		deltaGain = (m_threshold - frameIn) / m_ratio;
	}

	return deltaGain;
}

void CCompressor::XmlLoadAttribute(const CComBSTR& name, CComVariant& value)
{
	if (name == L"threshold")
	{
		value.ChangeType(VT_R8);
		m_threshold = value.dblVal;
	}
	else if (name == L"ratio")
	{
		value.ChangeType(VT_R8);
		m_ratio = value.dblVal;
	}
	else if (name == L"attack")
	{
		value.ChangeType(VT_R8);
		m_attack = value.dblVal;
	}
	else if (name == L"release")
	{
		value.ChangeType(VT_R8);
		m_release = value.dblVal;
	}
	else if (name == L"isUpwards")
	{
		value.ChangeType(VT_BOOL);
		m_isUpwards = value.boolVal;
	}
}
