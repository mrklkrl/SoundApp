#include "../SoundLib.h"
#include <iostream>
#include <string>

#define FILEPATH "../SoundLib/Test Data/1kHz_44100Hz_16bit_30sec.wav"

int main() 
{
	SoundLib::AudioObject testData(FILEPATH, "Test Data");
	testData.GetRMS(0);
	testData.GetPeak(0);
	std::cout << "Press Enter to exit." << std::endl;
	std::cin.ignore();
	return 0;
}