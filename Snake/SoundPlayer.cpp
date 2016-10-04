#include "SoundPlayer.hpp"

#include <SFML/Audio/Listener.hpp>

SoundPlayer::SoundPlayer()
	: soundBuffers()
	, sounds()
{
}

void SoundPlayer::load()
{
	soundBuffers.load(SoundEffects::ID::ButtonClick, "Button.wav");
	soundBuffers.load(SoundEffects::ID::ButtonHover, "Button.wav");
}

void SoundPlayer::play(SoundEffects::ID effect)
{
	play(effect, getListenerPosition());
}

void SoundPlayer::play(SoundEffects::ID effect, sf::Vector2f position)
{
	sounds.push_back(sf::Sound());
	sf::Sound &sound = sounds.back();

	sound.setBuffer(soundBuffers.get(effect));
	sound.play();
}

void SoundPlayer::removeStoppedSounds()
{
	sounds.remove_if([](const sf::Sound &s)
	{
		return s.getStatus() == sf::Sound::Stopped;
	});
}

void SoundPlayer::setListenerPosition(sf::Vector2f position)
{
	sf::Listener::setPosition(position.x, -position.y, 0);
}

sf::Vector2f SoundPlayer::getListenerPosition() const
{
	sf::Vector3f position = sf::Listener::getPosition();
	return sf::Vector2f(position.x, position.y);
}

