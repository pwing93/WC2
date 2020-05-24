
#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
//==============================================================================
/**
*/
class Wc2AudioProcessorEditor  : public AudioProcessorEditor
{
public:
    Wc2AudioProcessorEditor (Wc2AudioProcessor&, AudioProcessorValueTreeState&);
    ~Wc2AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Wc2AudioProcessor& processor;
    AudioProcessorValueTreeState& params;
    Slider threshSlider, slopeSlider, kneeSlider, attackSlider, releaseSlider;
    Label threshLabel, slopeLabel, kneeLabel, attackLabel, releaseLabel;
    std::unique_ptr<SliderAttachment> threshAttachment, slopeAttachment, kneeAttachment, attackAttachment, releaseAttachment;
    
    void addSlider(String name, String labelText, Slider& slider, Label& label, std::unique_ptr<SliderAttachment>& attachment)
    {
        addAndMakeVisible(slider);
        attachment.reset(new SliderAttachment (params, name, slider));
        label.setText(labelText, dontSendNotification);
        label.attachToComponent(&slider, true);
        addAndMakeVisible(label);
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Wc2AudioProcessorEditor)
};
