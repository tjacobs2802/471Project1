#pragma once
#include "CEffect.h"
#include <queue>
class CChorus :
	public CEffect
{

private:
	double m_amplitude;
	double m_frequency;
	double m_phase;
	double m_balanceOffset;
	double m_wetness;
	double m_delay;

	std::queue<double> m_frameHistory;
	int m_bufferIndex;
	int m_bufferSize;

public:
	CChorus(int channels, double sampleRate, double samplePeriod);
public:

	virtual void Process(const double* frameIn, double* frameOut, const double& time);
	virtual void XmlLoadAttribute(const ATL::CComBSTR& name, ATL::CComVariant& value);

	void Reset() override;
};
