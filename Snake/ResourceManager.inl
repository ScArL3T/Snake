// Main class

template<typename Resource, typename ID>
template<typename ...Args>
void ResourceManager<Resource, ID>::load(const ID &id, Args &&...args)
{
	auto temp = std::make_unique<Resource>();
	if (!temp->loadFromFile(std::forward<Args>(args)...)) 
		throw std::runtime_error("Failed to load file.");

	map.emplace(id, std::move(temp));
}

template<typename Resource, typename ID>
Resource &ResourceManager<Resource, ID>::get(const ID &id) const
{
	return *map.at(id);
}

// Music class

template<typename ID>
template<typename ...Args>
void ResourceManager<sf::Music, ID>::load(const ID &id, Args &&...args)
{
	auto temp = std::make_unique<sf::Music>();
	if (!temp->openFromFile(std::forward<Args>(args)...))
		throw std::runtime_error("Failed to load file.");

	map.emplace(id, std::move(temp));
}

template<typename ID>
sf::Music &ResourceManager<sf::Music, ID>::get(const ID &id) const
{
	return *map.at(id);
}