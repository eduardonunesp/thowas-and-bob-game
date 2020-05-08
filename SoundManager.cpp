#include "SoundManager.hpp"
#include <SFML/Audio.hpp>


SoundManager::SoundManager()
{
	// Load the sound in to the buffers
	fire_buffer.loadFromFile("sound/fire1.wav");
	fall_in_fire_buffer.loadFromFile("sound/fallinfire.wav");
	fall_in_water_buffer.loadFromFile("sound/fallinwater.wav");
	jump_buffer.loadFromFile("sound/jump.wav");
	reach_goal_buffer.loadFromFile("sound/reachgoal.wav");

	// Associate the sounds with the buffers
	fire_sound_1.setBuffer(fire_buffer);
	fire_sound_2.setBuffer(fire_buffer);
	fire_sound_3.setBuffer(fire_buffer);
	fall_in_fire_sound.setBuffer(fall_in_fire_buffer);
	fall_in_water_sound.setBuffer(fall_in_water_buffer);
	jump_sound.setBuffer(jump_buffer);
	reach_goal_sound.setBuffer(reach_goal_buffer);

	// When the player is 50 pixels away sound is full volume
	float minDistance = 150;
	// The sound reduces steadily as the player moves further away
	float attenuation = 15;

	// Set all the attenuation levels
	fire_sound_1.setAttenuation(attenuation);
	fire_sound_2.setAttenuation(attenuation);
	fire_sound_3.setAttenuation(attenuation);

	// Set all the minimum distance levels
	fire_sound_1.setMinDistance(minDistance);
	fire_sound_2.setMinDistance(minDistance);
	fire_sound_3.setMinDistance(minDistance);

	// Loop all the fire sounds
	// when they are played
	fire_sound_1.setLoop(true);
	fire_sound_2.setLoop(true);
	fire_sound_3.setLoop(true);
}

void SoundManager::play_fire(sf::Vector2f emitter_location, sf::Vector2f listerner_location)
{
	// Where is the listener? Thomas.
	sf::Listener::setPosition(listerner_location.x, listerner_location.y, 0.0f);

	switch (next_sound)
	{
	case 1:
		// Locate/move the source of the sound
		fire_sound_1.setPosition(emitter_location.x, emitter_location.y, 0.0f);

		if (fire_sound_1.getStatus() == sf::Sound::Status::Stopped)
		{
			// Play the sound, if its not already
			fire_sound_1.play();
		}
		break;

	case 2:
		// Do the same as previous for the second sound
		fire_sound_2.setPosition(emitter_location.x, emitter_location.y, 0.0f);

		if (fire_sound_2.getStatus() == sf::Sound::Status::Stopped)
		{
			fire_sound_2.play();
		}
		break;

	case 3:
		// Do the same as previous for the third sound
		fire_sound_3.setPosition(emitter_location.x, emitter_location.y, 0.0f);

		if (fire_sound_3.getStatus() == sf::Sound::Status::Stopped)
		{
			fire_sound_3.play();
		}
		break;
	}

	// Increment to the next fire sound
	next_sound++;

	// Go back to 1 when the third sound has been started
	if (next_sound > 3)
	{
		next_sound = 1;
	}
}

void SoundManager::play_fall_in_fire()
{
	fall_in_fire_sound.setRelativeToListener(true);
	fall_in_fire_sound.play();
}

void SoundManager::play_fall_in_water()
{
	fall_in_water_sound.setRelativeToListener(true);
	fall_in_water_sound.play();
}

void SoundManager::play_jump()
{
	jump_sound.setRelativeToListener(true);
	jump_sound.play();
}

void SoundManager::play_reach_goal()
{
	reach_goal_sound.setRelativeToListener(true);
	reach_goal_sound.play();
}
