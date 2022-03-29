#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <vector>

class MenuState : public GameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static MenuState* Instance()
	{
		return &m_MenuState;
	}

protected:
	MenuState() { }

private:
	static MenuState m_MenuState;

	std::vector<sf::Text> buttons;
	sf::Font font;
	sf::Text text;
	const int NUM_BUTTONS = 3;

	bool isTextClicked(sf::Text text, GameEngine* game);

	sf::Texture MenuBackground;
	sf::Sprite MenuBackgroundSprite;
};

