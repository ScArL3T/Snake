#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <Thor/Resources.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

class ResourceManager 
{
public:
	ResourceManager();
	~ResourceManager();

	void LoadTexture(int ID, std::string filename);
	void LoadSound(int ID, std::string filename);
	void LoadMusic(std::string filename);
	void LoadFont(int ID, std::string filename);
	void SetSprite(int ID);
	void SetSound(int ID);
	void DeleteSprite(int ID);
	void DeleteSound(int ID);

	thor::ResourceHolder<sf::Texture, int> TextureHold;
	thor::ResourceHolder<sf::SoundBuffer, int> SoundBufferHold;
	thor::ResourceHolder<sf::Font, int> FontHold;
	std::vector<sf::Sprite> SpriteHold;
	std::vector<sf::Sound> SoundHold;
	std::vector<sf::Music> MusicHold;
private:
	sf::Font font;
	sf::Sprite sprite;
	sf::Sound sound;
	sf::Music music;
};

#endif