#include "CraftingUI.h"
#include "PlayerManager.h"
#include "AudioManager.h"
#include "Text.h"

#include "RustyFloor.h"
#include "AncientFloor.h"
#include "FoodCheapBuilding.h"
#include "FoodExpensiveBuilding.h"
#include "OxigenCheapBuilding.h"
#include "OxigenExpenciveBuilding.h"

CraftingUI::CraftingUI(Game* game)
{
	this->game = game;
	button = new Button("res/img/boat/ui/CraftButton.png", WIDTH - 250, 650, 300, 100, game);
	active = false;

	// Floor
	craftables.push_back(new RustyFloor(0, 0, game));
	craftables.push_back(new AncientFloor(0, 0, game));

	// Oxigen
	craftables.push_back(new OxigenCheapBuilding(0, 0, game));
	craftables.push_back(new OxigenExpenciveBuilding(0, 0, game));

	// Hunger
	craftables.push_back(new FoodCheapBuilding(0, 0, game));
	craftables.push_back(new FoodExpensiveBuilding(0, 0, game));
}

/*
CraftingUI::CraftingUI(Game* game, GameLayer* layer)
{
	this->game = game;
	button = new Button("res/img/boat/ui/CraftButton.png", WIDTH - 250, 650, 300, 100, game);
	active = false;

	// Floor
	craftables.push_back(new RustyFloor(0, 0, game));
	craftables.push_back(new AncientFloor(0, 0, game));

	// Oxigen
	craftables.push_back(new OxigenCheapBuilding(0, 0, game));
	craftables.push_back(new OxigenExpenciveBuilding(0, 0, game));

	// Hunger
	craftables.push_back(new FoodCheapBuilding(0, 0, game));
	craftables.push_back(new FoodExpensiveBuilding(0, 0, game));

	this->layer = layer;
}
*/

void CraftingUI::draw()
{
	if (this->active) 
	{
		auto* playerData = PlayerManager::getInstance(game);

		// Fondo
		SDL_Rect* bg = new SDL_Rect();
		bg->x = WIDTH - 500;
		bg->y = 0;
		bg->w = 500;
		bg->h = HEIGHT;

		SDL_SetRenderDrawColor(game->renderer, 100, 100, 100, 160);
		SDL_RenderFillRect(game->renderer, bg);


		// Fondo objeto
		SDL_Rect* ibg = new SDL_Rect();
		ibg->x = WIDTH - 400;
		ibg->y = 100;
		ibg->w = 300;
		ibg->h = 300;

		SDL_SetRenderDrawColor(game->renderer, 50, 50, 50, 100);
		SDL_RenderFillRect(game->renderer, ibg);


		// Objeto
		Craftable* item = craftables.at(selectedItem);

		(new Text(item->name, WIDTH - 250, 50, game))
			->draw();

		item->x = WIDTH - 250;
		item->y = 250;
		item->width = 280;
		item->height = 280;

		item->draw();

		(new Text("Metal: " + std::to_string(item->priceMetal), WIDTH - 250, 470, game))
			->draw(
				playerData->metalAmount >= item->priceMetal? 0 : 255,
				playerData->metalAmount >= item->priceMetal ? 255 : 0,
				0);

		(new Text("Meat: " + std::to_string(item->priceMeat), WIDTH - 250, 500, game))
			->draw(
				playerData->meatAmount >= item->priceMeat ? 0 : 255,
				playerData->meatAmount >= item->priceMeat ? 255 : 0,
				0);

		(new Text("Ancient: " + std::to_string(item->priceAncient), WIDTH - 250, 530, game))
			->draw(
				playerData->ancientAmount >= item->priceAncient ? 0 : 255,
				playerData->ancientAmount >= item->priceAncient ? 255 : 0,
				0);

		(new Text(item->description, WIDTH - 250, 440, game))
			->draw(game->tinyFont);

		button->draw();
	}
}

void CraftingUI::handleClick()
{
	int motionX;
	int motionY;
	SDL_GetMouseState(&motionX, &motionY);

	if (button->containsPoint(motionX, motionY)) {
		if (PlayerManager::getInstance(game)->canBuild(craftables.at(selectedItem))) {
			craftables.at(selectedItem)->craft();
			PlayerManager::getInstance(game)->build(craftables.at(selectedItem));
			active = false;
		}
		else {
			AudioManager::getInstance()->PlayCannotBuild();
		}
	}
}

void CraftingUI::keysToControls(SDL_Event event)
{
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada
		switch (code) {
		case SDLK_LEFT:
			selectedItem = selectedItem <= 0 ? craftables.size() - 1 : selectedItem - 1;
			break;
		case SDLK_RIGHT:
			selectedItem = selectedItem >= craftables.size()-1 ? 0 : selectedItem + 1;
			break;
		case SDLK_RETURN:
			if (PlayerManager::getInstance(game)->canBuild(craftables.at(selectedItem))) {
				craftables.at(selectedItem)->craft();
				PlayerManager::getInstance(game)->build(craftables.at(selectedItem));
				active = false;
			}
			break;
		}
	}
}
