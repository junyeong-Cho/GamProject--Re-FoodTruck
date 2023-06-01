/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  SoundComponentManager.h
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    June 2, 2023
*/

#pragma once

#include <SFML/Audio.hpp>

#include <string>
#include <iostream>

#include "../Engine/Engine.h"


namespace CS230
{
	class Sound
	{
	public:
		Sound(const std::string& filename) : filename(filename) { }

		virtual void LoadFile() = 0;
		virtual void Play()		= 0;
	
	protected:
		std::string filename;
	};


	class MusicEffect : public Sound
	{
	public:
		MusicEffect(const std::string& filename);

		sf::Music    music;

		void         LoadFile() override;

		void         Play() override;
		void		 Stop();

	private:
		bool isMusicPlaying = false;
	};


	class SoundEffect : public Sound
	{
	public:
		SoundEffect(const std::string& filename);

		sf::SoundBuffer buffer;
		sf::Sound       sound;

		void			LoadFile() override;

		void            Play() override;
	};
}