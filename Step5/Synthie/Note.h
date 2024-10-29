#pragma once
#include <string>
class CNote
{
public:
	CNote();
	virtual ~CNote();
	int Measure() const { return m_measure; }
	double Beat() const { return m_beat; }
	const std::wstring &Instrument() const { return m_instrument; }
	IXMLDOMNode *Node() { return m_node; }
	/*void XmlLoad(IXMLDOMNode * xml, std::wstring & instrument);*/
	void XmlLoad(IXMLDOMNode* xml, std::wstring& instrument, std::wstring& effect);
	bool operator<(const CNote &b);
	const std::wstring& EffectID() const { return m_effectID; }
private:
	std::wstring m_instrument;

	// JUlia trying
	std::wstring m_effectID;
	//

	int m_measure;
	double m_beat;
	CComPtr<IXMLDOMNode> m_node;
};

