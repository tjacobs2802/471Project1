#pragma once
#include <vector>
#include "AudioEffect.h"

class EffectManager {
public:
    EffectManager();
    ~EffectManager();

    void AddEffect(AudioEffect* effect); // Add an effect to the manager
    void ProcessEffects(double* frameIn, double* frameOut); // Process all effects

private:
    std::vector<AudioEffect*> m_effects; // Store the effects
};

