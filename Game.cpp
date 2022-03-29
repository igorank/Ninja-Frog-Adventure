#include <iostream>
#include "Game.h"
#include "GameState.h"

void GameEngine::Init(int width, int height, const char* title)
{
	window.create(sf::VideoMode(width, height), title, sf::Style::Close);

	m_running = true;

	std::cout << "GameEngine Init\n";
}

void GameEngine::Cleanup()
{
	while (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	std::cout << "GameEngine Cleanup\n";
}

void GameEngine::ChangeState(GameState* state)
{
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PushState(GameState* state)
{
	if (!states.empty()) {
		states.back()->Pause();
	}

	states.push_back(state);
	states.back()->Init();
}

void GameEngine::PopState()
{
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	if (!states.empty()) {
		states.back()->Resume();
	}
}

void GameEngine::HandleEvents()
{
	states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
	states.back()->Update(this);
}

void GameEngine::Draw()
{
	states.back()->Draw(this);
}
