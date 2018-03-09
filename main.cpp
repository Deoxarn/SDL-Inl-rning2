#include "Game.h"

Game *game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();

	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart = 0;
	int frameTime = 0;

	game->Init("Fappalicious", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->Running())
	{
		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();
		//Update all objects etc positions etc
		//render changes to the display
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	//Cleanup
	game->CleanUp();

	return 0;

}