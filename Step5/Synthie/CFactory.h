#pragma once
#include <vector>
#include <memory>
#include "CEffect.h"

// CFactory class to create effects from XML nodes
class CFactory {
public:
    CFactory() = delete;

    CFactory(int channels, double sampleRate, double samplePeriod);

    std::vector<std::shared_ptr<CEffect>> XmlLoadEffects(IXMLDOMNode* xml);

private:
    int m_channels;
    double m_sampleRate;
    double m_samplePeriod;
};

