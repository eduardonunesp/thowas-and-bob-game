
#ifndef __SOUND_MANAGER_HPP
#define __SOUND_MANAGER_HPP

#include <SFML/Audio.hpp>

class SoundManager
{
private:
	// The buffers
	sf::SoundBuffer fire_buffer;
	sf::SoundBuffer fall_in_fire_buffer;
	sf::SoundBuffer fall_in_water_buffer;
	sf::SoundBuffer jump_buffer;
	sf::SoundBuffer reach_goal_buffer;

	// The Sounds
	sf::Sound fire_sound_1;
	sf::Sound fire_sound_2;
	sf::Sound fire_sound_3;
	sf::Sound fall_in_fire_sound;
	sf::Sound fall_in_water_sound;
	sf::Sound jump_sound;
	sf::Sound reach_goal_sound;

	// Which sound should we use next, fire 1, 2 or 3
	int next_sound = 1;

public:

	SoundManager();

	void play_fire(sf::Vector2f emitter_location, sf::Vector2f listener_location);
	void play_fall_in_fire();
	void play_fall_in_water();
	void play_jump();
	void play_reach_goal();
};

#endif
