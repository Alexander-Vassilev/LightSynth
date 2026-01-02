/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "AdsrComponent.h"
#include "OscComponent.h"
#include "FilterComponent.h"

//==============================================================================
/**
*/
class LightsparkSynthRealAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    LightsparkSynthRealAudioProcessorEditor (LightsparkSynthRealAudioProcessor&);
    ~LightsparkSynthRealAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox oscSelector;
    LightsparkSynthRealAudioProcessor& audioProcessor;
    OscComponent osc;
    AdsrComponent adsr{audioProcessor.apvts};
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscSelectAttachment;
    FilterComponent filter;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LightsparkSynthRealAudioProcessorEditor)
};
