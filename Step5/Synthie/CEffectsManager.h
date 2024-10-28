#pragma once
#include "CEffect.h"
#include <vector>
#include <memory>

class CEffectsGroup :
    public CEffect
{

protected:
    std::vector<std::shared_ptr<CEffect>> m_effects;

public:
    CEffectsGroup(int channels, double sampleRate, double samplePeriod) : CEffect(channels, sampleRate, samplePeriod) {}

    ~CEffectsGroup();

public:
    void XmlLoad(IXMLDOMNode* xml) override;
};

