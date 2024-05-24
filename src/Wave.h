#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>

class Wave
{
public:
	void write();
private:
	time_t generate_name();
	void write_as_bytes(std::ofstream& file, uint32_t value, uint32_t byte_size);
	
private:
	//Riff Chunk
	const std::string chunk_id = "RIFF";
	const std::string chunk_size = "----";
	const std::string format = "WAVE";

	//Fmt subchunk
	const std::string subchunk1_id = "fmt ";
	const uint32_t subchunk1_size = 16;
	const int audio_format = 1;
	const int num_channels = 2;
	uint32_t sample_rate = 44100;
	const uint32_t byte_rate = sample_rate * num_channels * (subchunk1_size / 2);
	const uint32_t block_align = num_channels * subchunk1_size * (subchunk1_size / 8);
	const uint32_t bits_per_sample =  16;

	//Data sub chunk
	const std::string subchunk2_id = "data";
	const std::string subchunk2_size = "----";
	uint32_t duration = 2;
	uint32_t max_amplitude = 32760;
	double frequency = 250.0;



	std::ofstream wav;




};

