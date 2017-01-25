#include "AudioManager.h"


AudioManager::AudioManager()
{
}

AudioManager& AudioManager::getInstance()
{
	static AudioManager instance;
	return instance;
}

bool AudioManager::hasSound(std::string _id)
{
	bool valid = true;

	// Try to access the corresponding Buffer
	try
	{
		buffers.at(_id);
	}
	catch (const std::out_of_range& oor)
	{
		// Set return value to false
		valid = false;
		// Log the error
		std::cerr << "AudioManager buffers: Out of Range error: " << oor.what() << "\n";
	}
	// Try to access the corresponding Sound
	try
	{
		sounds.at(_id);
	}
	catch (const std::out_of_range& oor)
	{
		// Set return value to false
		valid = false;
		// Log the error
		std::cerr << "AudioManager sounds: Out of Range error: " << oor.what() << "\n";
	}

	return valid;
}

bool AudioManager::hasMusic(std::string _id)
{
	bool valid = true;

	// Try to access the corresponding Music
	try
	{
		musics.at(_id);
	}
	catch (const std::out_of_range& oor)
	{
		// Set return value to false
		valid = false;
		// Log the error
		std::cerr << "AudioManager music: Out of Range error: " << oor.what() << "\n";
	}
	
	return valid;
}

void AudioManager::addSound(std::string _id)
{
	if (!hasSound(_id))
	{
		buffers.insert(std::pair<std::string, sf::SoundBuffer>(_id, sf::SoundBuffer()));
		if (!buffers.at(_id).loadFromFile(_id))
		{
			std::cout << "AudioManager buffer: File not found: " + _id + "\n";
		}
		sounds.insert(std::pair<std::string, sf::Sound>(_id, sf::Sound()));
		sounds.at(_id).setBuffer(buffers.at(_id));
	}
}

void AudioManager::playSound(std::string _id)
{
	if (hasSound(_id))
	{
		sounds.at(_id).play();
	}
}

void AudioManager::stopSound(std::string _id)
{
	if (hasSound(_id))
	{
		sounds.at(_id).stop();
	}
}

void AudioManager::addMusic(std::string _id)
{
	if (!hasMusic(_id))
	{
		musics.insert(std::pair<std::string, sf::Music>(_id, sf::Music()));
		if (!musics.at(_id).openFromFile(_id))
		{
			std::cout << "AudioManager buffer: File not found: " + _id + "\n";
		}
	}
}

void AudioManager::playMusic(std::string _id)
{
	if (hasMusic(_id))
	{
		musics.at(_id).play();
	}
}

void AudioManager::stopMusic(std::string _id)
{
	if (hasMusic(_id))
	{
		musics.at(_id).stop();
	}
}

AudioManager::~AudioManager()
{
}
