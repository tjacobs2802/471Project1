#pragma once
#include "CEffect.h"
#include <deque>

class CFlange :
	public CEffect
{
private:
	double m_amplitude;
	double m_frequency;
	double m_phase;
	double m_feedback;
	double m_wetness;

	std::deque<double> m_frameHistory;
	int m_bufferIndex;
	int m_delayIndex;

public:
	CFlange(int channels, double sampleRate, double samplePeriod);

	~CFlange();

public:

	virtual void Process(const double* frameIn, double* frameOut, const double& time);
	virtual void XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value);

	void Reset() override;
};