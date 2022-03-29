#include <iostream>
#include <SFML/Graphics.hpp>
#include "MenuState.h"
#include "GameState.h"
#include "Game.h"
#include "PlayState.h"

MenuState MenuState::m_MenuState;

void MenuState::Init()
{
    font.loadFromFile("data/arial.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setPosition(50, 50);
    text.setCharacterSize(24);
    text.setString("test");

    MenuBackground.loadFromFile("data/background.png");
    MenuBackgroundSprite.setTexture(MenuBackground);

    for (int i = 0; i < NUM_BUTTONS; i++)
    {
        buttons.push_back(text);
        buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * 50);
    }

    buttons[0].setString("Play Game");
    buttons[1].setString("Options");
    buttons[2].setString("Quit");

    std::cout << "MenuState Init\n";
}

void MenuState::Cleanup()
{
    //buttons.clear();
    
    std::cout << "MenuState Cleanup\n";
}

void MenuState::Pause()
{
    std::cout << "MenuState Pause\n";
}

void MenuState::Resume()
{
    std::cout << "MenuState Resume\n";
}

void MenuState::HandleEvents(GameEngine* game)
{
    sf::Event event;
    while (game->window.pollEvent(event))
    {
        for (int i = 0; i < NUM_BUTTONS; i++)
        {
            if (event.type == sf::Event::MouseMoved && isTextClicked(buttons[i], game))
                buttons[i].setFillColor(sf::Color::Green);
            else
                buttons[i].setFillColor(sf::Color::Black);
        }

        if (event.type == sf::Event::Closed)
            game->Quit();


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (isTextClicked(buttons[0], game))
                game->ChangeState(PlayState::Instance());
            if (isTextClicked(buttons[2], game))
                game->Quit();
        }
    }
}

bool MenuState::isTextClicked(sf::Text text, GameEngine* game)
{
    sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

    if (rect.contains(sf::Mouse::getPosition(game->window)))
        return true;

    return false;
}

void MenuState::Update(GameEngine* game)
{

}

void MenuState::Draw(GameEngine* game)
{
    game->window.clear(sf::Color::White);

    game->window.draw(MenuBackgroundSprite);

    for (int i = 0; i < NUM_BUTTONS; i++)
        game->window.draw(buttons[i]);

    game->window.display();
}
