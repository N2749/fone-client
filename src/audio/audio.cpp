#include <audio.h>
#include <iostream>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/SoundBufferRecorder.hpp>


// create the recorder
sf::SoundBufferRecorder recorder;

void init_audio()
{
	// if not available the audio is dead
	if (!sf::SoundBufferRecorder::isAvailable())
	{
		std::cout << "Error :P";
		return;
	}
}


void listen()
{
	std::cout << "Started Recording audio" << std::endl;
	recorder.start();
}

sf::SoundBuffer get_buffer()
{
	std::cout << "Audio recording stopped" << std::endl;
	recorder.stop();
	return recorder.getBuffer();
}
