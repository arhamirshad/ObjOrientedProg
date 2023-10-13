#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "AudioFile.h"

using namespace std;

Audio changeSampleRate(Audio copy, int newSampleRate);
Audio addNoise(Audio copy, double noiseScale);
Audio addNoiseSpikes(Audio copy, double noiseScale, double spikeFrequency);
Audio echoAudio(Audio copy, double delayInSeconds, double echoScale);
Audio reverseAudio(Audio copy);
Audio scaleVolume(Audio copy, double scale);
Audio smoothAudio(Audio copy);


