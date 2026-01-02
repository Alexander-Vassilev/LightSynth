/*
  ==============================================================================

    OscData.cpp
    Created: 27 Dec 2025 7:08:06pm
    Author:  alex

  ==============================================================================
*/

#include "OscData.h"
#include <numbers>


void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec) {
    fmOsc.prepare(spec);
    prepare(spec);
};

void OscData::setWaveType(const int choice) {

    switch (choice) {
    case 0: // Sine
        initialise([](float x) { return std::sin(x); });
        break;
    case 1: // Saw
        initialise([](float x) { return x / std::numbers::pi; });
        break;
    case 2: // Square
        initialise([](float x) { return x < 0.0f ? -1.0f : 1.0f; });
        break;
    default:
        jassertfalse;
        break;
    }
};

void OscData::setWaveFrequency(const int midiNoteNumber) {
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber) + fmMod);
    lastMidiNote = midiNoteNumber;
};

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block) {
    for (int channel = 0; channel < block.getNumChannels(); channel++) {
        for (int sample = 0; sample < block.getNumSamples(); sample++) {
            fmMod = fmOsc.processSample(block.getSample(channel, sample)) * fmDepth;
        }
    }

    process(juce::dsp::ProcessContextReplacing<float>(block));
}

void OscData::setFmParams(const float depth, const float freq) {
    fmOsc.setFrequency(freq);
    fmDepth = depth;
    setFrequency(juce::MidiMessage::getMidiNoteInHertz(lastMidiNote) + fmMod);
}