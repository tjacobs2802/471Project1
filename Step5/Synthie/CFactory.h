#pragma once
#include <vector>
#include <memory>
#include "CEffect.h"

class CFactory
{
	// Constructors & Methods
public:
	CFactory() = delete;

	CFactory(int channels, double sampleRate, double samplePeriod);

	std::vector<std::shared_ptr<CEffect>> XmlLoadEffects(IXMLDOMNode* xml);

private:
	int m_channels;
	double m_sampleRate;
	double m_samplePeriod;
};

