#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::LoadTexture(int ID, std::string filename)
{
	TextureHold.acquire(ID, thor::Resources::fromFile<sf::Texture>(filename));
	std::cout << ID << " " << filename << " texture loaded successfully." << std::endl;
	SetSprite(ID);
}

void ResourceManager::LoadSound(int ID, std::string filename)
{
	SoundBufferHold.acquire(ID, thor::Resources::fromFile<sf::SoundBuffer>(filename));
	std::cout << ID << " " << filename << " soundbuffer file loaded successfully." << std::endl;
	SetSound(1);
}

void ResourceManager::LoadMusic(std::string filename)
{
	music.openFromFile(filename);
	//MusicHold.push_back(music); EROARE
	std::cout << filename << " music file loaded successfully." << std::endl;
}

void ResourceManager::LoadFont(int ID, std::string filename)
{
	FontHold.acquire(ID, thor::Resources::fromFile<sf::Font>(filename));
	std::cout << ID << " " << filename << " font loaded successfully." << std::endl;
}

void ResourceManager::SetSprite(int ID)
{
	sprite.setTexture(TextureHold[ID]);
	SpriteHold.push_back(sprite);
	std::cout << ID << " sprite loaded successfully." << std::endl;
}

void ResourceManager::SetSound(int ID)
{
	sound.setBuffer(SoundBufferHold[ID]);
	SoundHold.push_back(sound);
	std::cout << ID << " sound loaded successfully." << std::endl;
}

void ResourceManager::DeleteSprite(int ID)
{
	//Stergerea elementului de pe pozitia ID
	SpriteHold.erase(SpriteHold.begin() + ID + 1);
	std::cout << "Sprite " << ID << " deleted." << std::endl;
}

void ResourceManager::DeleteSound(int ID)
{
	SoundHold.erase(SoundHold.begin() + ID + 1);
	std::cout << "Sound " << ID << " deleted." << std::endl;
}