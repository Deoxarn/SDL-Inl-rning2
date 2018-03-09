#include "Game.h"
#include "GameObject.h"

GameObject* player = nullptr;
GameObject* enemy = nullptr;



Game::Game()
{

}

Game::~Game()
{

}

void Game::HandleEvents()
{
	SDL_Event Event;

	SDL_PollEvent(&Event);
	switch (Event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}

void Game::Init(const char* windowTitle, int xpos, int ypos, int width, int height, bool fullscreen)
{

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Failed to initialize SDL! Error code: " << SDL_GetError() << std::endl;
		return;
	}

	window = SDL_CreateWindow(windowTitle, xpos, ypos, width, height, flags);
	if (window == nullptr)
	{
		std::cout << "Failed to Create window! SDL Error code: " << SDL_GetError << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == nullptr)
	{
		std::cout << "Failed to create SDL Renderer! Error code: " << SDL_GetError() << std::endl;
		return;
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		
	isRunning = true;

	player = new GameObject("assets/player.png", renderer, 0, 0);

	if (player == nullptr)
	{
		std::cout << "Failed to create player SDL error: " << SDL_GetError() << std::endl;
	}

	enemy = new GameObject("assets/enemy.png", renderer, 100, 100);

	if (enemy == nullptr)
	{
		std::cout << "Failed to load enemy! SDL error code: " << SDL_GetError() << std::endl;
	}

}

void Game::Update()
{
	counter++;
	player->Update();
	enemy->Update();
	std::cout << counter << std::endl;
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	//Add stuff to render
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game::CleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}