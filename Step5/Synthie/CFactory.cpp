#include "stdafx.h"
#include "CFactory.h"
#include "CCompressor.h"
#include "CFlange.h"
#include "CChorus.h"
#include "xmlhelp.h"

CFactory::CFactory(int channels, double sampleRate, double samplePeriod)
{
	m_channels = channels;
	m_samplePeriod = samplePeriod;
	m_sampleRate = sampleRate;
}

std::vector<std::shared_ptr<CEffect>> CFactory::XmlLoadEffects(IXMLDOMNode* xml)
{
	std::vector<std::shared_ptr<CEffect>> effects = std::vector<std::shared_ptr<CEffect>>();

	CComPtr<IXMLDOMNode> node;
	xml->get_firstChild(&node);
	for (; node != NULL; NextNode(node))
	{
		CComPtr<IXMLDOMNamedNodeMap> attributes;
		node->get_attributes(&attributes);
		long len;
		attributes->get_length(&len);

		CComBSTR nodeName;
		node->get_nodeName(&nodeName);

		
		if (nodeName == L"compress")
		{
			std::shared_ptr<CCompressor> compress = std::make_shared<CCompressor>(m_channels, m_sampleRate, m_samplePeriod);
			compress->XmlLoad(node);

			effects.push_back(compress);
		}
		else if (nodeName == L"flange")
		{
			std::shared_ptr<CFlange> flange = std::make_shared<CFlange>(m_channels, m_sampleRate, m_samplePeriod);
			flange->XmlLoad(node);

			effects.push_back(flange);
		}
		else if (nodeName == L"chorus" || nodeName == L"choir")
		{
			std::shared_ptr<CChorus> choir = std::make_shared<CChorus>(m_channels, m_sampleRate, m_samplePeriod);
			choir->XmlLoad(node);

			effects.push_back(choir);
		}
	}

	return effects;
}
