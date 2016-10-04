#ifndef SCORE_HPP
#define SCORE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Score : public sf::Drawable, public sf::Transformable
{
public:
	explicit Score(const sf::Font &font);

	void addScore();
	void resetScore();

	unsigned int getValue() const;
	sf::Vector2f getSize() const;

private:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

	sf::Text score;

	unsigned int count;
};

#endif