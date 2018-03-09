#pragma once
#ifndef TEXTURE_MANAGER_H_
#define TEXTURE_MANAGER_H_
#include "Game.h"


class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* render);

};



#endif // !TEXTURE_MANAGER_H_

