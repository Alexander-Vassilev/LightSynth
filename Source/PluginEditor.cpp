/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LightsparkSynthRealAudioProcessorEditor::LightsparkSynthRealAudioProcessorEditor (LightsparkSynthRealAudioProcessor& p)
    : AudioProcessorEditor (&p), 
    audioProcessor (p), 
    osc(audioProcessor.apvts, "OSC1WAVETYPE", "OSC1FMFREQ", "OSC1FMDEPTH"), 
    adsr(audioProcessor.apvts),
    filter(audioProcessor.apvts, "FILTERTYPE", "FILTERFREQ", "FILTERRES")
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 600);

    oscSelectAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.apvts, "OSC", oscSelector);
    addAndMakeVisible(adsr);
    addAndMakeVisible(osc);
    addAndMakeVisible(filter);
}

LightsparkSynthRealAudioProcessorEditor::~LightsparkSynthRealAudioProcessorEditor()
{
}

//==============================================================================
void LightsparkSynthRealAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void LightsparkSynthRealAudioProcessorEditor::resized()
{
    const auto paddingX = 5;
    const auto paddingY = 35;
    const auto paddingY2 = 270;

    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    osc.setBounds(10, 10, 200, 200);
    adsr.setBounds(getLocalBounds());
    filter.setBounds(paddingX, paddingY2, 300, 200);
}