// Windows doesn't like std::put_time (for good reasons, but we'll disable warnings for now)
#pragma warning(disable : 4996)

#include "SoundLib.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

namespace SoundLib {
	
	void PrintMsg(std::string message)
	{
		auto now = std::chrono::system_clock::now();
		auto now_c = std::chrono::system_clock::to_time_t(now);

		std::cout << std::put_time(std::localtime(&now_c), "%c") << " : " << message << std::endl;
	}
	double AudioObject::GetRMS(int channel)
	{
		PrintMsg("process started: GetRMS for " + this->Name);
		
		double RMS = 0;
		int numSamples = this->audioFile.getNumSamplesPerChannel();
		int bitDepth = this->audioFile.getBitDepth();

		PrintMsg("Iterating over samples in " + this->Name);
		for (int i = 0; i < numSamples; i++)
		{
			double currentSample = this->audioFile.samples[channel][i];
			currentSample = currentSample * currentSample;
			RMS += currentSample;
		}
		
		PrintMsg("Calculating RMS for " + this->Name);
		RMS = sqrt(RMS/numSamples);
		
		// AudioFile.cpp normalizes the range for 8 and 16 bit wav file samples to be between -1 and 1. 
		// How nice of them!
		RMS = PercentToDB(RMS);

		PrintMsg("RMS of " + this->Name + " : ");
		std::cout << RMS << std::endl;
		return RMS;
	}
	double AudioObject::GetPeak(int channel)
	{
		PrintMsg("process started: GetPeak for " + this->Name);

		double Peak = 0;
		int numSamples = this->audioFile.getNumSamplesPerChannel();

		PrintMsg("Iterating over samples in " + this->Name);
		for (int i = 0; i < numSamples; i++)
		{
			double currentSample = this->audioFile.samples[channel][i];
			currentSample = fabs(currentSample);
			if (currentSample > Peak)
			{
				Peak = currentSample;
			}
		}

		PrintMsg("Calculating Peak for " + this->Name);
		Peak = PercentToDB(Peak);

		PrintMsg("Peak of " + this->Name + " : ");
		std::cout << Peak << std::endl;
		return Peak;
	}

	//"percent" is represented as a decimal between 0 and 1.
	double AudioObject::PercentToDB(double percent)
	{
		return 10 * log10(percent);;
	}

	AudioObject::AudioObject(std::string filePath, std::string name)
	{
		this->Name = name;
		this->audioFile.load(filePath);
	}

	AudioObject::~AudioObject()
	{
	}
}
