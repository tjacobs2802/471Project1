#include "stdafx.h"
#include "CEffect.h"

CEffect::CEffect(int channels, double sampleRate, double samplePeriod)
{
	m_channels = channels;
	m_sampleRate = sampleRate;
	m_samplePeriod = samplePeriod;
	m_id = L"";
	m_gain = 1;
}

void CEffect::XmlLoad(IXMLDOMNode* xml)
{

	CComPtr<IXMLDOMNamedNodeMap> attributes;
	xml->get_attributes(&attributes);
	long len;
	attributes->get_length(&len);

	for (int i = 0; i < len; i++)
	{
		CComPtr<IXMLDOMNode> attrib;
		attributes->get_item(i, &attrib);

		CComBSTR name;
		attrib->get_nodeName(&name);

		CComVariant value;
		attrib->get_nodeValue(&value);

		if (name == L"id")
		{
			m_id = value.bstrVal;
		}
		else if (name == "gain")
		{
			value.ChangeType(VT_R8);
			m_gain = value.dblVal;
		}
		else
		{
			XmlLoadAttribute(name, value);
		}
	}
}