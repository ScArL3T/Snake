#ifndef STATES_H
#define STATES_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

class State
{
public:
	virtual void Initialize(sf::RenderWindow &window)
	{
	}
	virtual void Update(sf::RenderWindow &window)
	{
	}
	virtual void Draw(sf::RenderWindow &window)
	{
	}
};

class GameState
{
public:
	GameState()
	{
		state = nullptr;
	}

	void SetWindow(sf::RenderWindow &window)
	{
		this->window = &window;
		std::cout << "Window set." << std::endl;
	}

	void SetState(State *_state)
	{
		state = _state;
		if (state != nullptr)
		{
			state->Initialize(*window);
		}
	}

	void Update()
	{
		if (state != nullptr)
		{
			state->Update(*window);
		}
	}

	void Draw()
	{
		if (state != nullptr)
		{
			state->Draw(*window);
		}
	}
private:
	sf::RenderWindow *window;
	State *state;
};

extern GameState engine;
extern bool quit_game;

#endif