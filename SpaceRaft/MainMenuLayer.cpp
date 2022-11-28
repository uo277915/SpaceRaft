#include "MainMenuLayer.h"

MainMenuLayer::MainMenuLayer(Game* game)
	: Layer(game) {
	init();
	gamePad = SDL_GameControllerOpen(0);

	Logger::log(0, "MainMenuLayer", "initialized");
}

void MainMenuLayer::init() {
	// Fondo normal, sin velocidad
	background = new Background("res/img/main_menu/mmBackground.png", WIDTH * 0.5, HEIGHT * 0.5, game);
	button = new GameObject("res/img/main_menu/mmPlayButton.png", WIDTH * 0.5, HEIGHT * 0.7, 630, 205, game);
}

void MainMenuLayer::draw() {
	background->draw();
	button->draw();

	SDL_RenderPresent(game->renderer); // Renderiza NO PUEDE FALTAR
}

void MainMenuLayer::processControls() {
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

	//procesar controles, solo tiene uno
	if (controlContinue) {
		game->changeLayer(1);
		controlContinue = false;
	}
}

void MainMenuLayer::keysToControls(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada
		switch (code) {
		case SDLK_ESCAPE: // derecha
			game->loopActive = false;
			break;
		case SDLK_1:
			game->scale();
			break;
		case SDLK_SPACE: // dispara
			controlContinue = true;
			break;
		}
	}
}

void MainMenuLayer::mouseToControls(SDL_Event event) {
	// Modificación de coordenadas por posible escalado
	float motionX = event.motion.x / game->scaleLower;
	float motionY = event.motion.y / game->scaleLower;

	// Cada vez que hacen click
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (button->containsPoint(motionX, motionY)) {
			controlContinue = true;
		}
	}
}

void MainMenuLayer::gamePadToControls(SDL_Event event) {
	// Leer los botones
	bool buttonA = SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_A);

	if (buttonA) {
		controlContinue = true;
	}
}
