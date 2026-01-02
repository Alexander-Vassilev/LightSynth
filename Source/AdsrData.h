/*
  ==============================================================================

    AdsrData.h
    Created: 27 Dec 2025 5:56:26pm
    Author:  alex

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AdsrData : public juce::ADSR {
public:
    void updateADSR(const float attack, const float decay, const float sustain, const float release);
private:
    juce::ADSR::Parameters adsrParams;
};