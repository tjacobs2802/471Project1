#include "stdafx.h"
#include "EffectsManager.h"

EffectManager::EffectManager() {}

EffectManager::~EffectManager() {
    // Clean up effects
    for (auto effect : m_effects) {
        delete effect; // Delete each effect object
    }
}

void EffectManager::AddEffect(AudioEffect* effect) {
    m_effects.push_back(effect); // Add an effect to the manager
}

void EffectManager::ProcessEffects(double* frameIn, double* frameOut) {
    // Initialize output to zero
    for (int c = 0; c < 2; c++) {
        frameOut[c] = 0.0;
    }

    // Process each effect
    for (auto effect : m_effects) {
        double tempFrame[2]; // Temporary frame for each effect output
        effect->Process(frameIn, tempFrame); // Process the input frame

        // Mix the effect output into the final output
        for (int c = 0; c < 2; c++) {
            frameOut[c] += tempFrame[c];
        }
    }
}
