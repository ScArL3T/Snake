#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "Container.hpp"
#include "State.hpp"
#include <SFML/Audio.hpp>

class MenuState final : public State
{
public:
	explicit MenuState(StateManager &stack, States::Context context);

	bool handleEvent(const sf::Event &event) override;
	bool update(sf::Time dt) override;
	void draw() override;
	
private:
	sf::Texture texture;

	sf::Text title;
	sf::Sprite panelSprite;
	Container container;
};

#endif