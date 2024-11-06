#pragma once
#include "CEffect.h"
#include <vector>

class CCompressor :
	public CEffect
{
	// Enums
public:
	enum Phase
	{
		Hold,
		Attack,
		Active,
		Release
	};
public:
	CCompressor(int channels, double sampleRate, double samplePeriod);

	void Process(const double* frameIn, double* frameOut, const double& time) override;

private:
	std::vector<Phase> m_stages;
	std::vector<double> m_times;
	double m_threshold;
	double m_ratio;
	double m_attack = 0.01;
	double m_release = 0.1;
	bool m_isUpwards = false;
	double m_currentVol = 0;
private:

	double GetDeltaGain(double frameIn);

protected:

	void XmlLoadAttribute(const CComBSTR& name, CComVariant& value) override;
};

