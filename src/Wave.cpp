#include "Wave.h"

void Wave::write_as_bytes(std::ofstream& file, uint32_t value, uint32_t byte_size)
{
	file.write(reinterpret_cast<const char*>(&value), byte_size);
}

void Wave::write()
{
	this->wav.open("test.wav", std::ios::binary);
	if (this->wav.is_open()) {
		this->wav << this->chunk_id; //Riff Chunk writing
		this->wav << this->chunk_size;
		this->wav << this->format;


		this->wav << this->subchunk1_id;
		write_as_bytes(this->wav, this->subchunk1_size, 4);
		write_as_bytes(this->wav, this->audio_format, 2);
		write_as_bytes(this->wav, this->num_channels, 2);
		write_as_bytes(this->wav, this->sample_rate, 4);
		write_as_bytes(this->wav, this->byte_rate, 4);
		write_as_bytes(this->wav, this->block_align, 2);
		write_as_bytes(this->wav, this->bits_per_sample, 2);

		this->wav << this->subchunk2_id;
		this->wav << this->subchunk2_size;

		uint32_t start_audio = wav.tellp();

		for (uint32_t i = 0; i < this->sample_rate * this->duration; i++)
		{
			//
			double amplitude = static_cast<double>(i) / this->sample_rate * this->max_amplitude;
			double value = sin((2 * 3.14 * i * this->frequency) / sample_rate);

			double channel1 = amplitude * value / 2; //temporary
			double channel2 = (max_amplitude - amplitude) * value;

			write_as_bytes(this->wav, channel1, 2);
			write_as_bytes(this->wav, channel2, 2);

		}

		uint32_t end_audio = wav.tellp();
		wav.seekp(start_audio - 4); // offset to write subchunk2 size
		write_as_bytes(this->wav, end_audio - start_audio, 4);

		wav.seekp(4, std::ios::beg); //chunk size wrtiting
		write_as_bytes(this->wav, end_audio - 8, 4);


	}
	
	wav.close();
}

time_t Wave::generate_name()
{
	time_t current_time = time(NULL);


	return current_time;
}
