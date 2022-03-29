#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "GameState.h"
#include "IntroState.h"
#include "MenuState.h"

IntroState IntroState::m_IntroState;

void IntroState::Init()
{
    std::cout << "IntroState Init\n";
}

void IntroState::Cleanup()
{
    std::cout << "IntroState Cleanup\n";
}

void IntroState::Pause()
{
    std::cout << "IntroState Pause\n";
}

void IntroState::Resume()
{
    std::cout << "IntroState Resume\n";
}

void IntroState::HandleEvents(GameEngine* game)
{
    sf::Event event;
    while (game->window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            game->ChangeState(MenuState::Instance());
        if (event.type == sf::Event::Closed)
            game->Quit();
    }
}

void IntroState::Update(GameEngine* game)
{

}

void IntroState::Draw(GameEngine* game)
{

}
