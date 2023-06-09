/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  Sound.h
Project:    GAM150
Author:     Junyeong cho
Created:    June 3, 2023
Updated:    June  9, 2023
*/
#pragma once

#include <SFML/Audio.hpp>

#include <string>
#include <vector>
#include <memory>
#include "../Engine/ComponentManager.h"
#include "../Engine/Engine.h"

namespace CS230
{
	class MusicEffect : public CS230::Component
	{
	public:
		MusicEffect();
		void AddMusicFile(const std::string& filename);
		void LoadFile(const std::string& filename);

		void Play(int index);
		void Stop();

		void SetVolume(float volume);

	private:
		std::vector<std::unique_ptr<sf::Music>> musicList;
		bool isMusicPlaying = false;
	};


	class SoundEffect : public CS230::Component
	{
	public:
		SoundEffect();
		void AddSoundFile(const std::string& filename);
		void LoadFile(const std::string& filename);

		void Play(int index);

	private:
		std::vector<sf::SoundBuffer> buffers;
		std::vector<sf::Sound> sounds;

		bool isSoundPlaying = false;
	};
}
