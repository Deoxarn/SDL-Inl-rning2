#include "TextureManager.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* fileName, SDL_Renderer* render)
{
	SDL_Surface* tmpSurface = nullptr;
	SDL_Texture* texture = nullptr;
	
	tmpSurface = IMG_Load(fileName);
	if (tmpSurface == nullptr)
	{
		std::cout << "Failed to load texture: " << fileName << " " << SDL_GetError() << std::endl;
	}

	texture = SDL_CreateTextureFromSurface(render, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	if (texture == nullptr)
	{
		std::cout << "Failed to Create texture from surface! " << SDL_GetError() << std::endl;
	}

	return texture;
}