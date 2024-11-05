#pragma once
#include "CEffect.h"
#include <vector>

class CNoiseGate :
	public CEffect
{
public:
	enum Phase
	{
		Closed,
		Attack,
		Open,
		Hold,
		Release
	};

private:
	std::vector<Phase> m_phases;

	std::vector<double> m_times;
	double m_threshold;
	double m_attack;
	double m_hold;
	double m_release;



public:
	CNoiseGate(int channels, double sampleRate, double samplePeriod);

	void Process(const double* frameIn, double* frameOut, const double& time) override;

protected:
	void XmlLoadAttribute(const CComBSTR& name, CComVariant& value) override;
};
