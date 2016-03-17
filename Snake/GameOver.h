#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "State.h"
#include "Score.h"
#include <iostream>
#include <SFML/Audio.hpp>

class GameOver final : public State
{
public:
	explicit GameOver(StateManager &stack, sf::RenderWindow &window);
	~GameOver();

	void handleEvent(const sf::Event &event) override;
	void update(sf::Time dt) override;
	void draw() override;

private:
	sf::Text gameover, enter;
	sf::Font font;
	sf::Music music;
};

#endif