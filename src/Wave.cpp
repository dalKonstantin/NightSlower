#include "Wave.h"

void Wave::write_as_bytes(std::ofstream& file, uint32_t value, uint32_t byte_size)
{
	file.write(reinterpret_cast<const char*>(&value), byte_size);
}

void Wave::write()
{
	this->wav.open( + ".wav", std::ios::binary);
	if (this->wav.is_open()) {
		this->wav << this->chunk_id;
		this->wav << this->chunk_size;
		this->wav << this->format;
		write_as_bytes(this->wav, this->subchunk1_size, 4);
		write_as_bytes(this->wav, this->audio_format, 2);
		write_as_bytes(this->wav, this->num_channels, 2);
		write_as_bytes(this->wav, this->sample_rate, 4);
		write_as_bytes(this->wav, this->byte_rate, 4);
		write_as_bytes(this->wav, this->block_align, 2);
		write_as_bytes(this->wav, this->bits_per_sample, 2);

	}
}

std::string Wave::generate_name()
{
	std::string name;s

	return name;
}
