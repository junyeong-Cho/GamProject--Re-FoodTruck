/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Frame.cpp
Project:    GAM150
Author:     Junyeong cho
Created:    June 3, 2023
Updated:    June  9, 2023
*/
#include "Sound.h"

namespace CS230
{
#pragma region MusicEffect
	MusicEffect::MusicEffect() {}


	void MusicEffect::AddMusicFile(const std::string& filename)
	{
		std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();
		if (!music->openFromFile(filename))
		{
			Engine::GetLogger().LogError("Failed to load music file: " + filename);
		}
		else
		{
			musicList.push_back(std::move(music));
		}
	}


	void MusicEffect::LoadFile(const std::string& filename)
	{
		AddMusicFile(filename);
	}


	void MusicEffect::Play(int index)
	{
		if (index >= 0 && index < musicList.size())
		{
			musicList[index]->setLoop(true);
			musicList[index]->setVolume(50);
			if (!isMusicPlaying)
			{
				musicList[index]->play();
				Engine::GetLogger().LogEvent("Now playing: " + std::to_string(index));


				isMusicPlaying = true;
			}
		}
	}

	void MusicEffect::Stop()
	{
		for (auto& music : musicList)
		{
			music->stop();
		}

		isMusicPlaying = false;
	}

	void MusicEffect::SetVolume(float volume)
	{
		for (auto& music : musicList)
		{
			music->setVolume(volume);
		}
	}

#pragma endregion

#pragma region SoundEffect
	SoundEffect::SoundEffect() { }


	void SoundEffect::AddSoundFile(const std::string& filename)
	{
		sf::SoundBuffer buffer;
		if (!buffer.loadFromFile(filename))
		{
			Engine::GetLogger().LogError("Failed to load sound file: " + filename);
		}
		else
		{
			sf::Sound sound;
			sound.setBuffer(buffer);
			sounds.push_back(sound);
			buffers.push_back(buffer);
		}
	}


	void SoundEffect::LoadFile(const std::string& filename)
	{
		AddSoundFile(filename);
	}


	void SoundEffect::Play(int index)
	{
		if (index >= 0 && index < sounds.size())
		{
			sounds[index].setBuffer(buffers[index]);
			sounds[index].setVolume(55);

			sounds[index].play();

			if (sounds[index].getStatus() == sf::Sound::Stopped)
			{
				sounds[index].~Sound();
			}


			Engine::GetLogger().LogEvent("Soundeffect played: " + std::to_string(index));
		}
	}
#pragma endregion
}
