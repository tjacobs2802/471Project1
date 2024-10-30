#pragma once
#include "AudioNode.h"
class CAR :
	public CAudioNode
{
public:
	CAR();
	~CAR();
private:
	double m_duration;  // Total duration for the note
	double m_time;      // Current time of the envelope
	double m_attack;    // Duration of the attack phase
	double m_release;   // Duration of the release phase
	CAudioNode* m_source; // The audio source to apply the envelope tovv
public:
	void SetSource(CAudioNode* const &source) { m_source = source; }
	void SetDuration(double d) { m_duration = d; }
	void SetAttack(double a) { m_attack = a; }
	void SetRelease(double r) { m_release = r; }
	virtual void Start();
	virtual bool Generate();

	double GetEnvelope() const; // New method to get the current envelope value
};

