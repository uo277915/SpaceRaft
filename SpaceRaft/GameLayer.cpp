#include "GameLayer.h"

GameLayer::GameLayer(Game* game)
	: Layer(game) {
	//llama al constructor del padre : Layer(renderer)
	background = new Background("res/img/boat/background.png", WIDTH * 0.5, HEIGHT * 0.5, game);

	init();

}

void GameLayer::init() {

	FileManager::getInstance()->loadPlayer();
	FileManager::getInstance()->loadShip();

	Logger::log(0, "GameLayer", "Initialized");
}

void GameLayer::processControls() {
	// obtener controles
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_CONTROLLERDEVICEADDED) {
			gamePad = SDL_GameControllerOpen(0);
			if (gamePad == NULL) {
				cout << "error en GamePad" << endl;
			}
			else {
				cout << "GamePad conectado" << endl;
			}
		}

		gamePadToControls(event);
		keysToControls(event);
		mouseToControls(event);
	}
}

void GameLayer::update() {


}

void GameLayer::draw() {
	
	background->draw();

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

void GameLayer::mouseToControls(SDL_Event event) {
	// Modificación de coordenadas por posible escalado
	float motionX = event.motion.x / game->scaleLower;
	float motionY = event.motion.y / game->scaleLower;

	// Cada vez que hacen click
	if (event.type == SDL_MOUSEBUTTONDOWN) {

	}
}

void GameLayer::gamePadToControls(SDL_Event event) {
	// Leer los botones
	bool buttonA = SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_A);

	if (buttonA) {

	}
}