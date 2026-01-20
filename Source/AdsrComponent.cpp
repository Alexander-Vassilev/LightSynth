/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 27 Dec 2025 5:56:37pm
    Author:  alex

  ==============================================================================
*/

#include "AdsrComponent.h"

AdsrComponent::AdsrComponent(juce::AudioProcessorValueTreeState& apvts) {
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;

    attackAttachment = std::make_unique<SliderAttachment>(apvts, "ATTACK", attackSlider);
    decayAttachment = std::make_unique<SliderAttachment>(apvts, "DECAY", decaySlider);
    sustainAttachment = std::make_unique<SliderAttachment>(apvts, "SUSTAIN", sustainSlider);
    releaseAttachment = std::make_unique<SliderAttachment>(apvts, "RELEASE", releaseSlider);

    setSliderParams(attackSlider);
    setSliderParams(decaySlider);
    setSliderParams(sustainSlider);
    setSliderParams(releaseSlider);
}

AdsrComponent::~AdsrComponent() {

}

void AdsrComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void AdsrComponent::resized() {
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 1;
    const auto sliderWidth = bounds.getWidth() / 16 - padding;
    const auto sliderHeight = bounds.getHeight() / 3;
    const auto sliderStartX = bounds.getWidth() / 2 + bounds.getWidth() / 4;
    const auto sliderStartY = bounds.getHeight() / 2 + bounds.getHeight() / 6;

    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
}

void AdsrComponent::setSliderParams(juce::Slider& slider) {
    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 25);
    addAndMakeVisible(slider);
}
