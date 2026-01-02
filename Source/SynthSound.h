/*
  ==============================================================================

    SynthSound.h
    Created: 27 Dec 2025 1:08:44pm
    Author:  alex

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
public:
    bool appliesToNote(int midiNoteNumber) override { return true; };
    bool appliesToChannel(int midiChannel) override { return true; };
};