#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>
using namespace std;

class GameState;

class GameEngine
{
public:
	void Init(int width, int height, const char* title);
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; }
	void Quit() { m_running = false; }

	sf::RenderWindow window;
private:
	vector<GameState*> states;
	bool m_running;
};
