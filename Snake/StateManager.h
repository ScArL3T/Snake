#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "State.h"

class StateManager : private sf::NonCopyable
{
public:
	explicit StateManager(sf::RenderWindow &window);
	~StateManager();

	void pushState(States::ID state);
	void popState();
	void clearStates();

	void handleEvent(const sf::Event &event);
	void update(sf::Time dt);
	void draw();

private:
	State::Ptr createState(States::ID state);
	void       applyChanges();

	enum class Action
	{
		None = 0,
		Push,
		Pop,
		Clear
	};

	std::vector<std::pair<Action, States::ID>> queue;
	std::vector<State::Ptr> stateStack;
	State::Ptr			    state;

	sf::RenderWindow       &window;
};

#endif