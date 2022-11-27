#include "GameLayer.h"

GameLayer::GameLayer(Game* game)
	: Layer(game) {
	//llama al constructor del padre : Layer(renderer)
	init();
}

void GameLayer::init() {
	
}

void GameLayer::processControls() {
	// obtener controles
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		keysToControls(event);
	}
}

void GameLayer::update() {

	cout << "update GameLayer" << endl;
}

void GameLayer::draw() {
	
	SDL_RenderPresent(game->renderer); // Renderiza
}

void GameLayer::keysToControls(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada
		switch (code) {
		case SDLK_ESCAPE:
			game->loopActive = false;
			break;
		case SDLK_0:
			game->scale();
			break;
		case SDLK_d: // derecha
			break;
		case SDLK_a: // izquierda
			break;
		case SDLK_w: // arriba
			break;
		case SDLK_s: // abajo
			break;
		case SDLK_SPACE: // dispara
			break;

		case SDLK_1:
			break;
		case SDLK_2:
			break;
		}


	}
	if (event.type == SDL_KEYUP) {
		int code = event.key.keysym.sym;
		// Levantada
		switch (code) {
		case SDLK_d: // derecha
			break;
		case SDLK_a: // izquierda
			break;
		case SDLK_w: // arriba
			break;
		case SDLK_s: // abajo
			break;
		case SDLK_SPACE: // dispara
			break;
		}

	}

}