#include "StoryLayer.h"

StoryLayer::StoryLayer(Game* game)
	: Layer(game) {
	init();
	gamePad = SDL_GameControllerOpen(0);

	Logger::log(0, "StoryLayer", "initialized");
}

void StoryLayer::init() {
	backgrounds.push_back(new Background("res/img/story/story1.png", WIDTH * 0.5, HEIGHT * 0.5, game));
	backgrounds.push_back(new Background("res/img/story/story2.png", WIDTH * 0.5, HEIGHT * 0.5, game));
	backgrounds.push_back(new Background("res/img/story/story3.png", WIDTH * 0.5, HEIGHT * 0.5, game));

	bgIterator = backgrounds.begin();
	background = *bgIterator;
}

void StoryLayer::nextBackground() {
	currentBG++;
	if (currentBG >= backgrounds.size()-1) {
		game->changeLayer(2);
	}
	else {
		std::advance(bgIterator, 1);
		background = *bgIterator;
	}
}

void StoryLayer::draw() {
	background->draw();

	SDL_RenderPresent(game->renderer); // Renderiza NO PUEDE FALTAR
}

void StoryLayer::processControls() {
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
		nextBackground();
		controlContinue = false;
	}
}

void StoryLayer::keysToControls(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada
		switch (code) {
		case SDLK_ESCAPE: // derecha
			game->loopActive = false;
			break;
		case SDLK_SPACE: // dispara
			controlContinue = true;
			break;
		}
	}
}

void StoryLayer::mouseToControls(SDL_Event event) {
	// Modificación de coordenadas por posible escalado
	float motionX = event.motion.x / game->scaleLower;
	float motionY = event.motion.y / game->scaleLower;

	// Cada vez que hacen click
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		controlContinue = true;
	}
}

void StoryLayer::gamePadToControls(SDL_Event event) {
	// Leer los botones
	bool buttonA = SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_A);

	if (buttonA) {
		controlContinue = true;
	}
}
