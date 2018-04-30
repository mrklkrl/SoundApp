#pragma once
#include "SoundLib.h"
#include "Third Party\AudioFile\AudioFile.h"
#include <vector>

namespace SoundLib {
	void PrintMsg(std::string message);

	class AudioObject 
	{
	public:
		AudioFile<double> audioFile;
		std::string Name;
		double GetRMS(int channel);
		double GetPeak(int channel);
		double PercentToDB(double percent);
		AudioObject();
		AudioObject(std::string filePath, std::string name);
		~AudioObject();
	};
}