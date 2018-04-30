#include "SoundLib.h"
#include <iostream>

namespace SoundLib {
	
	void PrintMsg()
	{
		std::cout << "Hey" << std::endl;
	}
	double AudioObject::GetRMS(int channel)
	{
		double RMS = 0;
		int numSamples = this->audioFile.getNumSamplesPerChannel();
		int bitDepth = this->audioFile.getBitDepth();
		
		for (int i = 0; i < numSamples; i++)
		{
			double currentSample = this->audioFile.samples[channel][i];
			currentSample = currentSample * currentSample;
			RMS += currentSample;
		}
		
		RMS = sqrt(RMS/numSamples);
		
		switch (bitDepth)
		{
		case 8:
			RMS = 10 * log10(RMS / 127);
			break;
		case 16:
			RMS = 10 * log10(RMS/32760);
			break;
		case 32:
			RMS = 10 * log10(RMS);
			break;
		default:
			break;
		}
		
		return RMS;
	}
	double AudioObject::GetPeak(int channel)
	{
		double Peak = 0;
		int numSamples = this->audioFile.getNumSamplesPerChannel();
		for (int i = 0; i < numSamples; i++)
		{
			double currentSample = this->audioFile.samples[channel][i];
			currentSample = fabs(currentSample);
			if (currentSample > Peak)
			{
				Peak = currentSample;
			}
		}
		Peak = PercentToDB(Peak);
		return Peak;
	}

	//"percent" is represented as a decimal between 0 and 1.
	double AudioObject::PercentToDB(double percent)
	{
		return 10 * log10(percent);;
	}
	AudioObject::AudioObject()
	{
	}
	AudioObject::AudioObject(std::string filePath)
	{
		this->audioFile.load(filePath);
	}

	AudioObject::~AudioObject()
	{
	}
}
