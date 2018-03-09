#pragma once
#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_
#include "Game.h"
#include <iostream>

class GameObject
{
public:
	GameObject(const char* texture, SDL_Renderer* renderer, int x, int y);
	~GameObject();

	void Render();
	void Update();

private:

	int xpos = 0;
	int ypos = 0;

	SDL_Texture* texture = nullptr;
	SDL_Renderer* render = nullptr;
	SDL_Rect sourceRect, destRect;

};


#endif // !GAME_OBJECT_H_

