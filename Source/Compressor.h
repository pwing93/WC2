/*
  ==============================================================================

    Compressor.h
    Created: 22 May 2020 2:47:55pm
    Author:  Peter Wing

  ==============================================================================
*/

#include <JuceHeader.h>
#include "CircularBuffer.h"
#pragma once


class Compressor
{
public:
    Compressor();
    float compressSample(float data, float thresh, float ratio, float attack, float release, float knee);
    float interpolatePoints(float* xPoints, float* yPoints, float detectedValue);
    
private:
    CircularBuffer buffer;
    float tav, rms, gain;
    
};


