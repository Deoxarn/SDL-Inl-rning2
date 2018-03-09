#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* texture, SDL_Renderer* render, int x, int y)
{
	GameObject::render = render;

	if (GameObject::render == nullptr)
	{
		std::cout << "GameObject failed to create render! " << SDL_GetError() << std::endl;
	}

	GameObject::texture = TextureManager::LoadTexture(texture, GameObject::render);

	if (GameObject::texture == nullptr)
	{
		std::cout << "Failed to create object texture! " << SDL_GetError() << std::endl;
	}
	xpos = x;
	ypos = y;

}

void GameObject::Render()
{
	SDL_RenderCopy(GameObject::render, GameObject::texture, &sourceRect, &destRect);
}

void GameObject::Update()
{
	///DEBUGGING
	xpos++;
	ypos++;

	sourceRect.h = 32;
	sourceRect.w = 32;
	sourceRect.x = 0;
	sourceRect.y = 0;

	destRect.h = sourceRect.h * 2;
	destRect.w = sourceRect.w * 2;
	destRect.x = xpos;
	destRect.y = ypos;
}