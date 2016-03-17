#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "StatesID.h"

// Forward declaration
class StateManager;

class State : private sf::NonCopyable
{
public:
	using Ptr = std::unique_ptr<State>; // typedef std::unique_ptr<State> Ptr;

	explicit State(StateManager &stack, sf::RenderWindow &window);
	virtual ~State() = default;

	virtual void handleEvent(const sf::Event &event) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void draw() = 0;

	bool isActive();

protected:
	void pushState(States::ID state);
	void popState();
	void clearStates();

	void setActive(bool value);

	sf::RenderWindow &getWindow();

private:
	StateManager	 &stack;
	sf::RenderWindow &window;

	bool active;
};

#endif