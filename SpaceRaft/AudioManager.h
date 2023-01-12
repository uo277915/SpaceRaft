#pragma once
#include "Audio.h"

class AudioManager
{
public:
	static AudioManager* getInstance();

	void PlayMainMenuMusic();
	void PlayClickMainMenu();

	void PlayGameMusic();
	void PlayPickTrash();
	void PlayBuild();
	void PlayCannotBuild();
	void PlayDestroy();

protected:
	static AudioManager* audioManagerInstance;
	AudioManager();

	// Audios
	Audio* mainMenuMusic;
	Audio* clickPlay;

	Audio* gameMusic;
	Audio* pickTrash;
	Audio* build;
	Audio* cannotBuild;
	Audio* destroy;
};

