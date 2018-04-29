#include "../SoundLib.h"
#include <iostream>
#include <string>

int main() 
{
	SoundLib::PrintMsg();
	std::string FilePath = "../SoundLib/Test Data/1kHz_44100Hz_16bit_30sec.wav";
	SoundLib::AudioObject testData(FilePath);
	std::cout << "RMS of file: " << testData.GetRMS(0) << "dB" <<std::endl;
	std::cout << "Peak of file: " << testData.GetPeak(0) << "dB" << std::endl;
	return 0;
}