#include "PlayerDataUI.h"
#include "PlayerManager.h"


void PlayerDataUI::draw(SDL_Renderer* renderer, Game* game)
{
	auto* playerData = PlayerManager::getInstance(game);

	// Barras de vida, hambre y oxigeno.
	SDL_Rect* healthBase = new SDL_Rect();
	healthBase->x = 10;
	healthBase->y = 10;
	healthBase->w = 300;
	healthBase->h = 25;

	SDL_Rect* healthBar = new SDL_Rect();
	healthBar->x = 10;
	healthBar->y = 10;
	healthBar->w = (playerData->health * 300) / playerData->MAX_HEALTH;
	healthBar->h = 25;

	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderFillRect(renderer, healthBase);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, healthBar);

	SDL_Rect* hungerBase = new SDL_Rect();
	hungerBase->x = 10;
	hungerBase->y = 45;
	hungerBase->w = 300;
	hungerBase->h = 25;

	SDL_Rect* hungerBar = new SDL_Rect();
	hungerBar->x = 10;
	hungerBar->y = 45;
	hungerBar->w = (playerData->hunger * 300) / playerData->MAX_HUNGER;
	hungerBar->h = 25;

	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderFillRect(renderer, hungerBase);
	(new Text(std::to_string((int)(-playerData->hungerStep)), 330, 55, game))->draw(0, 255, 0);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, hungerBar);

	SDL_Rect* oxigenBase = new SDL_Rect();
	oxigenBase->x = 10;
	oxigenBase->y = 80;
	oxigenBase->w = 300;
	oxigenBase->h = 25;

	SDL_Rect* oxigenBar = new SDL_Rect();
	oxigenBar->x = 10;
	oxigenBar->y = 80;
	oxigenBar->w = (playerData->oxigen * 300) / playerData->MAX_OXIGEN;
	oxigenBar->h = 25;

	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderFillRect(renderer, oxigenBase);
	(new Text(std::to_string((int)(-playerData->oxigenStep)), 330, 95, game))->draw(0, 0, 255);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, oxigenBar);

	for (int i = 0; i < playerData->items->size(); i++) {
		SDL_Rect* itemBox = new SDL_Rect();
		itemBox->x = 350 + (i*110);
		itemBox->y = 10;
		itemBox->w = 100;
		itemBox->h = 100;

		if (playerData->selectedItem == i) 
		{
			SDL_SetRenderDrawColor(renderer, 255, 223, 0, 10);
		}
		else 
		{
			SDL_SetRenderDrawColor(renderer, 50, 50, 50, 10);
		}
		SDL_RenderDrawRect(renderer, itemBox);
		playerData->items->at(i)->draw(350 + (i * 110), 10, 100, 100);
	}
	
	// Recursos
	(new Text(std::to_string(playerData->metalAmount), 20, HEIGHT - 100, game))->draw(100, 100, 100);
	(new Text(std::to_string(playerData->meatAmount), 20, HEIGHT - 70, game))->draw(255, 100, 100);
	(new Text(std::to_string(playerData->ancientAmount), 20, HEIGHT - 40, game))->draw(20, 255, 200);

}
