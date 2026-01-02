/*
  ==============================================================================

    FilterComponent.h
    Created: 28 Dec 2025 3:55:32pm
    Author:  alex

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class FilterComponent : public juce::Component {
public:
    FilterComponent(juce::AudioProcessorValueTreeState& apvts, juce::String filterTypeSelectorId,
        juce::String filterFreqId, juce::String filterResId);
    ~FilterComponent();

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox filterTypeSelector{ "Filter Type" };
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeSelectorAttachment;

    juce::Slider filterFreqSlider;
    juce::Slider filterResSlider;

    using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    std::unique_ptr<Attachment> filterFreqAttachment;
    std::unique_ptr<Attachment> filterResAttachment;
    
    juce::Label filterSelectorLabel {"Wave Type", "Wave Type" };
    juce::Label filterFreqLabel { "Filter Freq", "Filter Freq" };
    juce::Label filterResLabel {"Filter Res", "Filter Res" };

    void setSliderWithLabel(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts,
        juce::String paramId, std::unique_ptr<Attachment>& attachment);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FilterComponent)
};