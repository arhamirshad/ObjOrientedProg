#include <iostream>
#include "AudioFile.h"
#include <time.h>   

using namespace std;

Audio changeSampleRate(Audio copy, int newSampleRate) {
     Audio original = copy;
     original.setSampleRate(newSampleRate);
     return original;
}
Audio scaleVolume(Audio copy, double scale){
    Audio original = copy;  
    int channel = 0;
    int numSamples = original.getNumSamplesPerChannel();

    for (int i = 0; i < numSamples; i++)
    {
	    original.samples[0][i] = scale * original.samples[0][i];
    }

    return original;
}

Audio addNoise(Audio copy, double noiseScale){

    Audio original = copy;  
    srand(time(0));
      
    int numSamples = original.getNumSamplesPerChannel();


    for (int i = 0; i < numSamples; i++){

        double x = (rand()/(double)RAND_MAX)*noiseScale;

        if(rand()%2 == 1 ){            
            original.samples[0][i] =  (x) + original.samples[0][i];            
        }
        else {
            original.samples[0][i] =  original.samples[0][i] - x ;
        }
	    

    }
    return original;
}
Audio addNoiseSpikes(Audio copy, double noiseScale, double spikeFrequency){

Audio original = copy;  
    srand(time(0));
        

    int channel = 0;
    int numSamples = original.getNumSamplesPerChannel();

    for (int i = 0; i < numSamples; i++){
        double y = rand()/(double)RAND_MAX;
        if(y <= spikeFrequency){
            double x = (rand()/(double)RAND_MAX)*noiseScale;

            if(rand()%2 == 1 ){            
                original.samples[0][i] =  (x) + original.samples[0][i];            
            }
            else {
                original.samples[0][i] =  original.samples[0][i] - x ;
            }   

        }
        
    }
    return original;

}

Audio reverseAudio(Audio copy){

    Audio original = copy;  
    int channel = 0;
    int numSamples = original.getNumSamplesPerChannel();
    for (int i = 0; i < numSamples; i++)    {

       
	    original.samples[0][i] =  copy.samples[0][numSamples-i-1];

    }
    return original;
}

Audio echoAudio(Audio copy, double delayInSeconds, double echoScale){
    Audio original = copy;  
    int sampleRate = original.getSampleRate();
    int delayInSamples = sampleRate*delayInSeconds;
    int channel = 0;
    int numSamples = original.getNumSamplesPerChannel();

    for (int i = delayInSamples; i < numSamples; i++){

        original.samples[0][i] = copy.samples[0][i] + (echoScale * copy.samples[0][i-delayInSamples]);

    }
    return original;
}
Audio smoothAudio(Audio copy){
    Audio original = copy; 
    int channel = 0;
    int numSamples = original.getNumSamplesPerChannel();

    for (int i = 1; i < numSamples-1; i++)
    {
         original.samples[channel][i] = (copy.samples[channel][i] + copy.samples[channel][i-1]+copy.samples[channel][i+1])/3;
    }
    original.samples[channel][0] = (copy.samples[channel][0] + copy.samples[channel][1])/2;
    original.samples[channel][numSamples-1] = (copy.samples[channel][numSamples-2] + copy.samples[channel][numSamples-1])/2;
    return original;
    

}