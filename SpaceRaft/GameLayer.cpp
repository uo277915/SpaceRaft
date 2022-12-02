#include "GameLayer.h"

GameLayer::GameLayer(Game* game)
	: Layer(game) {
	//llama al constructor del padre : Layer(renderer)
	background = new Background("res/img/boat/background.png", WIDTH * 0.5, HEIGHT * 0.5, 2, game);
	collisionController = new CollisionController();
	shipManager = new ShipManager();
	tilePointer = new TilePlacingPointer(game);
	buildPointer = new BuildingPlacingPointer(game);

}

void GameLayer::init() {

	// Collisions & Movement
	collisionController->init();
	collisionController->addObject(PlayerManager::getInstance()->player);

	FileManager::getInstance()->loadPlayer();
	FileManager::getInstance()->loadShip(shipManager, collisionController, game);

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

	// Eje X
	if (controlMoveX > 0) {
		PlayerManager::getInstance()->player->moveX(1);
	}
	else if (controlMoveX < 0) {
		PlayerManager::getInstance()->player->moveX(-1);
	}
	else {
		PlayerManager::getInstance()->player->moveX(0);
	}

	// Eje Y
	if (controlMoveY > 0) {
		PlayerManager::getInstance()->player->moveY(1);
	}
	else if (controlMoveY < 0) {
		PlayerManager::getInstance()->player->moveY(-1);
	}
	else {
		PlayerManager::getInstance()->player->moveY(0);
	}

	collisionController->update();

	tilePointer->update(shipManager);
	buildPointer->update(shipManager);
	background->update();
}

void GameLayer::draw() {
	
	background->draw();
	shipManager->draw();
	tilePointer->draw();
	buildPointer->draw();
	PlayerManager::getInstance()->player->draw();

	SDL_RenderPresent(game->renderer); // Renderiza
}

void GameLayer::keysToControls(SDL_Event event) {

	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada
		switch (code) {
		case SDLK_ESCAPE:
			FileManager::getInstance()->saveShip(shipManager);
			game->loopActive = false;
			break;
		case SDLK_0:
			game->scale();
			break;
		case SDLK_d: // derecha
			controlMoveX = 1;
			break;
		case SDLK_a: // izquierda
			controlMoveX = -1;
			break;
		case SDLK_w: // arriba
			controlMoveY = 1;
			break;
		case SDLK_s: // abajo
			controlMoveY = -1;
			break;
			// TODO: Remove
		case SDLK_1:
			tilePointer->loadTile(new RustyFloor(0, 0, game));
			tilePointer->active = true;
			break;
		}
	}
		if (event.type == SDL_KEYUP) {
			int code = event.key.keysym.sym;
			// Levantada
			switch (code) {
			case SDLK_d: // derecha
				if (controlMoveX > 0) {
					controlMoveX = 0;
				}
				break;
			case SDLK_a: // izquierda
				if (controlMoveX < 0) {
					controlMoveX = 0;
				}
				break;
			case SDLK_w: // arriba
				if (controlMoveY > 0) {
					controlMoveY = 0;
				}
				break;
			case SDLK_s: // abajo
				if (controlMoveY < 0) {
					controlMoveY = 0;
				}
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
		tilePointer->handleClick(shipManager, collisionController);
	}
}

void GameLayer::gamePadToControls(SDL_Event event) {
	// Leer los botones
	bool buttonA = SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_A);

	if (buttonA) {

	}
}