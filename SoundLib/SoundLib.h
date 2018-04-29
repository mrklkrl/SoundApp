#pragma once
#include "SoundLib.h"
#include "Third Party\AudioFile\AudioFile.h"
#include <vector>

namespace SoundLib {
	void PrintMsg();

	class AudioObject 
	{
	public:
		AudioFile<double> audioFile;
		double GetRMS(int channel);
		double GetPeak(int channel);
		double PercentToDB(double percent);
		AudioObject();
		AudioObject(std::string filePath);
		~AudioObject();
	};
}