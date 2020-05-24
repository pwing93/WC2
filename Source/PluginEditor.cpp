
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Wc2AudioProcessorEditor::Wc2AudioProcessorEditor (Wc2AudioProcessor& p, AudioProcessorValueTreeState& state)
    : AudioProcessorEditor (&p), processor (p), params(state)
{
    addSlider("thresh", "Threshold", threshSlider, threshLabel, threshAttachment);
    addSlider("ratio", "Ratio", slopeSlider, slopeLabel, slopeAttachment);
    addSlider("knee", "Knee", kneeSlider, kneeLabel, kneeAttachment);
    addSlider("attack", "Attack", attackSlider, attackLabel, attackAttachment);
    addSlider("release", "Release", releaseSlider, releaseLabel, releaseAttachment);
    
    setSize (400, 300);
}

Wc2AudioProcessorEditor::~Wc2AudioProcessorEditor()
{
}

//==============================================================================
void Wc2AudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    getLookAndFeel().setColour (Slider::thumbColourId, Colours::goldenrod);
    
}

void Wc2AudioProcessorEditor::resized()
{
    threshSlider.setBounds(100, 0, 200, 50);
    slopeSlider.setBounds(100, 50, 200, 50);
    kneeSlider.setBounds(100, 100, 200, 50);
    attackSlider.setBounds(100, 150, 200, 50);
    releaseSlider.setBounds(100, 200, 200, 50);
}
