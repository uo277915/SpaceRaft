#pragma once

// Todas las librerias de SDL y otras utilidades
#include <iostream>
#include <string>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map> 

// Valores generales
#define WIDTH 480
#define HEIGHT 320

#include "Layer.h"
class Layer;

/*
 Class that controls the main game.
*/
class Game
{
public:
	// Methods
	/*Main game method*/
	Game();
	/*Changes the game scale*/
	void scale();
	/*Defines the game time loop*/
	void loop();
	/*Returns a texture set on a file
	* @param filename The name of the texture
	*/

	SDL_Texture* getTexture(string filename);

	// Variables
	map<string, SDL_Texture*> mapTextures; // map - cache
	TTF_Font* font;
	bool scaledToMax = false;
	float scaleLower = 1;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool loopActive;
	Layer* gameLayer;
};
