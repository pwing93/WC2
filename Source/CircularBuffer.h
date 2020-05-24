/*
  ==============================================================================

    CircularBuffer.h
    Created: 18 May 2020 10:25:34am
    Author:  Peter Wing

  ==============================================================================
*/


#include <JuceHeader.h>
#pragma once

class CircularBuffer
{
public:
    
    CircularBuffer();
    CircularBuffer(int buffersize, int delayLength);
    float getData();
    void setData(float data);
    void nextSample();
    
private:
    
    AudioSampleBuffer buffer;
    int writeIndex;
    int readIndex;
    int delayLength;
};

