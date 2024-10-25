// AudioEffect.h
#pragma once
#include "Note.h"

class AudioEffect {
public:
    virtual ~AudioEffect(); 
    virtual void SetNote(const CNote* note) = 0; 
    virtual void Process(double* frameIn, double* frameOut) = 0; 
};
