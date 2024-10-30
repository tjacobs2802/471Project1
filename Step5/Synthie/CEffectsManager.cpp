#include "stdafx.h"
#include "CEffectsManager.h"
#include "CFactory.h"

CEffectsGroup::~CEffectsGroup()
{
	m_effects.clear();
}

void CEffectsGroup::XmlLoad(IXMLDOMNode* xml)
{
	CEffect::XmlLoad(xml);

	CFactory factory(m_channels, m_sampleRate, m_samplePeriod);
	m_effects = factory.XmlLoadEffects(xml);
}
