#pragma once
#ifndef GAME_H_
#define GAME_H_
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void Init(const char* windowTitle, int xpos, int ypos, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void CleanUp();

	bool Running() { return isRunning; }

private:

	///Debugg unly
	int counter = 0;

	bool isRunning = false;
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	SDL_Texture *playerTexture = nullptr;

	SDL_Rect destR;


};


#endif // !GAME_H_

