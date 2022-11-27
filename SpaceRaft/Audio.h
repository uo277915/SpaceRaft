#pragma once
#include <iostream>
#include <string> 
using namespace std;

#include <SDL.h>;
#include <SDL_mixer.h> // libreria de audio

/*Class that controls an audio*/
class Audio
{
public:
	// Methods
	/* Loads and plays an audio
	*
	* @param filename The name of the audio file
	* @param loop Whether the audio loops
	*/
	Audio(string filename, bool loop);
	/*Audio destructor*/
	~Audio();
	/*Plays the audio*/
	void play();

	// Variable
	bool loop;
	Mix_Music* mix; // Lib mixer
	SDL_AudioSpec wavSpec; // Lib SDL Standard
	Uint32 wavLength;
	Uint8* wavBuffer;
	SDL_AudioDeviceID deviceId;
};


