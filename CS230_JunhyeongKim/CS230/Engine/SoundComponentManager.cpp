/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  SoundComponentManager.cpp
Project:    CS230 Engine
Author:     Junyeong Cho
Created:    June 2, 2023
*/

#include "SoundComponentManager.h"

namespace CS230
{
//Volume = 60 
#pragma region MusicEffect

	MusicEffect::MusicEffect(const std::string& filename) : Sound(filename), isMusicPlaying(false)
	{
		LoadFile();
	}


	void MusicEffect::LoadFile()
	{
		if (!music.openFromFile(filename))
		{
			std::cout << "Failed to load music file: " << filename << std::endl;
		}
	}
	
	//Volume
	void MusicEffect::Play()
	{
		music.setLoop  (true);
		music.setVolume(60);

		if (isMusicPlaying == false)
		{
			music.play();

			Engine::GetLogger().LogEvent("Now playing: " + filename);

			isMusicPlaying = true;
		}
		

		
	}


	void MusicEffect::Stop()
	{
		music.stop();
		isMusicPlaying = false;
	}

#pragma endregion


//Volume = 35
#pragma region SoundEffect

	SoundEffect::SoundEffect(const std::string& filename) : Sound(filename)
	{
		LoadFile();
	}


	void SoundEffect::LoadFile()
	{
		if (!buffer.loadFromFile(filename))
		{
			std::cout << "Failed to load sound file: " << filename << std::endl;
		}
		else
		{
			sound.setBuffer(buffer);
		}
	}

	//Volume
	void SoundEffect::Play()
	{
		sound.setBuffer(buffer);
		sound.play();
		sound.setVolume(35);

		Engine::GetLogger().LogEvent("Soundeffect played: " + filename);

	}

#pragma endregion

}