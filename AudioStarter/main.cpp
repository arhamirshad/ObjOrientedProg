#include <iostream>
#include "AudioFile.h"
#include "Effects.h"
using namespace std;

int main()
{
    Audio audioFile;
    audioFile.load("swnotry.wav");
    audioFile.save("test.wav");
    audioFile.printSummary();

   
    
    Audio cSampleRate = changeSampleRate(audioFile, 100);
    cSampleRate.save("changeSampleRate.wav");

    Audio sVol = scaleVolume(audioFile, 0.5);
    sVol.save("scaleVolume.wav");

    Audio aNoise = addNoise(audioFile, 0.5);
    aNoise.save("addNoise.wav");

    Audio aNoiseSpikes = addNoiseSpikes(audioFile, 0.5 , 0.1);
    aNoiseSpikes.save("addNoiseSpikes.wav");

    Audio rAudio = reverseAudio(audioFile);
    rAudio.save("reverseAudio.wav");

    Audio eAudio = echoAudio(audioFile, 2 , 0.5);
    eAudio.save("echoAudio.wav");

    Audio sAudio = smoothAudio(audioFile);
    sAudio.save("smoothAudio.wav");

    return 0;



}
