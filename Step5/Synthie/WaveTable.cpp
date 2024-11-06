#include "stdafx.h"
#include "Wavetable.h"
#include "Notes.h"
#include <string>

using namespace std;

// Constructor - Initialize default values if needed
CWavetable::CWavetable()
{
}

// Start() - Initializes and starts the waveform and AR components
void CWavetable::Start()
{
    // Configure waveform and AR components with sample rate and duration
    m_waveform.SetSampleRate(GetSampleRate());
    m_waveform.Start();
    m_time = 0;

    // Link AR object to waveform and configure AR parameters
    m_ar.SetSource(&m_waveform);
    m_ar.SetSampleRate(GetSampleRate());
    m_ar.SetAttack(m_waveform.Attack());
    m_ar.SetRelease(m_waveform.Release());

    // Start AR for the synthesis chain
    m_ar.Start();
}

// Generate() - Generates audio samples for each frame
bool CWavetable::Generate()
{
    // Generate audio sample from the waveform and AR
    m_waveform.Generate();
    bool valid = m_ar.Generate();

    // Capture generated sample into output frame
    m_frame[0] = m_ar.Frame(0);
    m_frame[1] = m_ar.Frame(1);

    // Update time
    m_time += GetSamplePeriod();

    // Return true until the duration is reached
    return valid;
}

// SetNote() - Sets note parameters from an XML note node
void CWavetable::SetNote(CNote* note)
{
    // Retrieve attributes from the XML node
    CComPtr<IXMLDOMNamedNodeMap> attributes;
    note->Node()->get_attributes(&attributes);
    long len;
    attributes->get_length(&len);

    // Process each attribute
    for (int i = 0; i < len; i++)
    {
        CComPtr<IXMLDOMNode> attrib;
        attributes->get_item(i, &attrib);

        // Get attribute name and value
        CComBSTR name;
        attrib->get_nodeName(&name);
        CComVariant value;
        attrib->get_nodeValue(&value);

        // Process based on attribute name
        if (name == "duration")
        {
            value.ChangeType(VT_R8);
            double durationInSecs = value.dblVal * (NUM_SECS_IN_MINUTE / m_bpm);
            m_ar.SetDuration(durationInSecs);
            m_waveform.SetDuration(durationInSecs);
        }
        else if (name == "note")
        {
            SetNoteSample(value, /* isGlissando */ false);
        }
        else if (name == "gliss")
        {
            SetNoteSample(value, /* isGlissando */ true);
        }
    }
}

// Helper function to load sample for a note or glissando
void CWavetable::SetNoteSample(const CComVariant& value, bool isGlissando)
{
    wstring noteName(value.bstrVal, SysStringLen(value.bstrVal));
    int sampleSlot = isGlissando ? 1 : 0;
    m_waveform.LoadSamp(m_waveform.GetSample(noteName), sampleSlot);

    // Set next note if this is the primary note (not a glissando)
    if (!isGlissando)
    {
        m_waveform.SetNextNote(99); // 99 as placeholder; adjust logic as needed
    }
}
