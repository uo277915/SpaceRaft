#include "GameLayer.h"
#include "FileManager.h" 
#include "Text.h"
#include "Audio.h"  
#include "Tile.h"
#include "RustyFloor.h"
#include "PlayerManager.h"

#include <list>
#include "CollisionController.h"
#include "AudioManager.h"

GameLayer::GameLayer(Game* game)
	: Layer(game) {
	//llama al constructor del padre : Layer(renderer)
	background = new Background("res/img/boat/background.png", WIDTH * 0.5, HEIGHT * 0.5, 2, game);
	collisionController = new CollisionController();
	shipManager = new ShipManager();

	tileRemover = new TileRemovePointer(game);
	buildRemover = new BuildingRemovePointer(game);

	tilePointer = new TilePlacingPointer(game);
	buildPointer = new BuildingPlacingPointer(game);

	playerDataUI = new PlayerDataUI();
	trashSpawner = new TrashSpawner(game);
	craftingUI = new CraftingUI(game);

}

void GameLayer::init() {

	// Collisions & Movement
	collisionController->init();
	collisionController->addObject(PlayerManager::getInstance(game)->player);

	FileManager::getInstance()->loadPlayer(game);
	FileManager::getInstance()->loadShip(shipManager, collisionController, game);

	Mix_FadeOutMusic(1000);
	AudioManager::getInstance()->PlayGameMusic();

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
		PlayerManager::getInstance(game)->player->moveX(1);
	}
	else if (controlMoveX < 0) {
		PlayerManager::getInstance(game)->player->moveX(-1);
	}
	else {
		PlayerManager::getInstance(game)->player->moveX(0);
	}

	// Eje Y
	if (controlMoveY > 0) {
		PlayerManager::getInstance(game)->player->moveY(1);
	}
	else if (controlMoveY < 0) {
		PlayerManager::getInstance(game)->player->moveY(-1);
	}
	else {
		PlayerManager::getInstance(game)->player->moveY(0);
	}

	collisionController->update();

	tilePointer->update(shipManager);
	tileRemover->update(shipManager);

	buildPointer->update(shipManager);
	buildRemover->update(shipManager);

	background->update();
	PlayerManager::getInstance(game)->update();

	trashSpawner->update();
}

void GameLayer::draw() {
	
	background->draw();
	trashSpawner->draw();

	shipManager->draw();

	tilePointer->draw();
	tileRemover->draw();

	buildPointer->draw();
	buildRemover->draw();

	PlayerManager::getInstance(game)->player->draw();

	// ui
	playerDataUI->draw(game->renderer, game);

	craftingUI->draw();

	SDL_RenderPresent(game->renderer); // Renderiza
}

void GameLayer::keysToControls(SDL_Event event) {

	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada
		switch (code) {
		case SDLK_ESCAPE:
			FileManager::getInstance()->saveShip(shipManager, game);
			FileManager::getInstance()->savePlayer(game);
			game->loopActive = false;
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
		case SDLK_c: // craft
			craftingUI->active = !craftingUI->active;
			break;
		case SDLK_1:
			PlayerManager::getInstance(game)->SelectItem(0, this);
			break;
		case SDLK_2:
			PlayerManager::getInstance(game)->SelectItem(1, this);
			break;
		case SDLK_3:
			PlayerManager::getInstance(game)->SelectItem(2, this);
			break;
		case SDLK_4:
			PlayerManager::getInstance(game)->SelectItem(3, this);
			break;
		case SDLK_5:
			PlayerManager::getInstance(game)->SelectItem(4, this);
			break;
		case SDLK_6:
			PlayerManager::getInstance(game)->SelectItem(5, this);
			break;
		case SDLK_7:
			PlayerManager::getInstance(game)->SelectItem(6, this);
			break;
		case SDLK_8:
			PlayerManager::getInstance(game)->SelectItem(7, this);
			break;
		case SDLK_9:
			PlayerManager::getInstance(game)->SelectItem(8, this);
			break;
		case SDLK_0:
			PlayerManager::getInstance(game)->SelectItem(9, this);
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
	if (event.type == SDL_MOUSEWHEEL) {
		if (event.wheel.y > 0) // scroll up
		{
			PlayerManager::getInstance(game)->NextItem(this);
		}
		else if (event.wheel.y < 0) // scroll down
		{
			PlayerManager::getInstance(game)->PreviousItem(this);
		}
	}

	craftingUI->keysToControls(event);
}

void GameLayer::mouseToControls(SDL_Event event) {
	// Modificación de coordenadas por posible escalado
	float motionX = event.motion.x / game->scaleLower;
	float motionY = event.motion.y / game->scaleLower;

	// Cada vez que hacen click
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		tilePointer->handleClick(shipManager, collisionController);
		tileRemover->handleClick(shipManager, collisionController);

		buildPointer->handleClick(shipManager, collisionController);
		buildRemover->handleClick(shipManager, collisionController);
		
		if (grabbable) {
			trashSpawner->handleClick();
		}

		craftingUI->handleClick();
	}
}

void GameLayer::gamePadToControls(SDL_Event event) {
	// Leer los botones
	bool buttonA = SDL_GameControllerGetButton(gamePad, SDL_CONTROLLER_BUTTON_A);

	if (buttonA) {

	}
}

void GameLayer::buildTile(Tile* tile)
{
	tilePointer->tileToPlace = (Tile*) tile->clone();
	tilePointer->active = true;
}

void GameLayer::buildBuilding(Building* building)
{
	buildPointer->buildingToPlace = (Building*) building->clone();
	buildPointer->active = true;
}
