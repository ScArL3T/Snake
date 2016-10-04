#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"
#include "Apple.hpp"
#include "Snake.hpp"
#include "Score.hpp"
#include <SFML/Audio.hpp>

class GameState final : public State
{
public:
	explicit GameState(StateManager &stack, States::Context context);

	bool handleEvent(const sf::Event &event) override;
	bool update(sf::Time dt) override;
	void draw() override;

private:
	bool appleOnHead();
	bool appleOnSnake();

	Snake snake;
	Apple apple;

	sf::Vector2f newpos;

	sf::Font font;
	sf::Sound sound;
	sf::SoundBuffer buffer;

	sf::RectangleShape line;
	sf::Text infoText;
};

#endif