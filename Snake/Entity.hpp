#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Entity : public sf::Drawable, public sf::Transformable
{
public:
	using Ptr = std::unique_ptr<Entity>;

	virtual ~Entity() = default;

	virtual void handleEvent(const sf::Event &event) = 0;
	virtual void update(sf::Time dt) = 0;
};

#endif

