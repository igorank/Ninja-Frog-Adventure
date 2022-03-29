#include <SFML/Graphics.hpp>
#include "Game.h"
#include "IntroState.h"

int main()
{
	GameEngine game;
	game.Init(800, 600, "Ninja Frog Adventure");

	game.ChangeState(IntroState::Instance());

	while (game.Running())
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	game.Cleanup();

	return 0;
}
