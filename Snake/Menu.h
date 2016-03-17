#ifndef MENU_H
#define MENU_H

#include "Button.h"
#include "State.h"

class Menu final : public State
{
public:
	explicit Menu(StateManager &stack, sf::RenderWindow &window);
	~Menu();

	void handleEvent(const sf::Event &event) override;
	void update(sf::Time dt) override;
	void draw() override;
	
private:
	sf::Text play, quit;
	sf::Font font;
	Button button;

};

#endif