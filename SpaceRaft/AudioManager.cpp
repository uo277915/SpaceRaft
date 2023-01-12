#include "AudioManager.h"

AudioManager* AudioManager::audioManagerInstance = nullptr;

AudioManager* AudioManager::getInstance()
{
    if (audioManagerInstance == nullptr) {
        audioManagerInstance = new AudioManager();
    }
    return audioManagerInstance;
}

AudioManager::AudioManager()
{
    mainMenuMusic = new Audio("res/sound/mainmenu/music.mp3", true);
    clickPlay = new Audio("res/sound/mainmenu/play.wav", false);

    gameMusic = new Audio("res/sound/ship/music.mp3", true);
    pickTrash = new Audio("res/sound/ship/pick.wav", false);
    build = new Audio("res/sound/ship/build.wav", false);
    cannotBuild = new Audio("res/sound/ship/cannot.wav", false);
    destroy = new Audio("res/sound/ship/destroy.wav", false);
}

void AudioManager::PlayMainMenuMusic()
{
    mainMenuMusic->play();
}

void AudioManager::PlayClickMainMenu()
{
    clickPlay->play();
}

void AudioManager::PlayGameMusic()
{
    gameMusic->play();
}

void AudioManager::PlayPickTrash()
{
    pickTrash->play();
}

void AudioManager::PlayBuild()
{
    build->play();
}

void AudioManager::PlayCannotBuild()
{
    cannotBuild->play();
}

void AudioManager::PlayDestroy()
{
    destroy->play();
}
