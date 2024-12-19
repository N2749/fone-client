#include <iostream>
#include <audio.h>
#include <SFML/Audio/SoundBuffer.hpp>

int main() {
	init_audio();
	listen();
	bool stop = false;
	int some;
	std::cout << "To stop recording type 1" << std::endl;
	do {
		std::cin >> some;
		stop = some == 1;
	}
	while(!stop);

	std::string recording_filename = "test.ogg";

	get_buffer().saveToFile(recording_filename);

	return 0;
}
