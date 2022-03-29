#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayState.h"
#include "GameState.h"
#include "Game.h"

PlayState PlayState::m_PlayState;

void PlayState::Init()
{
    std::cout << "PlayState Init\n";
}

void PlayState::Cleanup()
{
    std::cout << "PlayState Cleanup\n";
}

void PlayState::Pause()
{
    std::cout << "PlayState Pause\n";
}

void PlayState::Resume()
{
    std::cout << "PlayState Resume\n";
}

void PlayState::HandleEvents(GameEngine* game)
{
    sf::Event event;
    while (game->window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            //game->PushState(PauseState::Instance());
        }
        if (event.type == sf::Event::Closed)
        {
            game->Quit();
        }
    }
}

void PlayState::Update(GameEngine* game)
{

}

void PlayState::Draw(GameEngine* game)
{
    game->window.clear(sf::Color::White);

    game->window.display();
}
