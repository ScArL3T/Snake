#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "AppleObject.h"
#include "Score.h"
#include <SFML/Audio.hpp>

class Game final : public State
{
public:
	explicit Game(StateManager &stack, sf::RenderWindow &window);
	~Game();

	void handleEvent(const sf::Event &event) override;
	void update(sf::Time dt) override;
	void draw() override;

private:
	SnakeObject SO;
	AppleObject AO;
	Score score;

	bool paused, enterKey, spawned;
	sf::Text pausedText;
	sf::Text enterText, escText;
	sf::RectangleShape bg;
	sf::Vector2f newpos;

	sf::Font font;
	sf::Sound sound;
	sf::SoundBuffer buffer;
};

#endif