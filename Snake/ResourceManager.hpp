#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <unordered_map>
#include <memory>
#include <stdexcept>

#include <SFML/Audio.hpp>

template<typename Resource, typename ID>
class ResourceManager
{
public:
	ResourceManager() = default;

	template<typename ...Args>
	void load(const ID &id, Args &&...args);

	Resource &get(const ID &id) const;
private:
	std::unordered_map<ID, std::unique_ptr<Resource>> map;
};

template<typename ID>
class ResourceManager<sf::Music, ID>
{
public:
	ResourceManager() = default;

	template<typename ...Args>
	void load(const ID &id, Args && ...args);

	sf::Music &get(const ID &id) const;
private:
	std::unordered_map<ID, std::unique_ptr<sf::Music>> map;
};

#include "ResourceManager.inl"

#endif