
#ifndef __PLAYABLE_CHARACTER
#define __PLAYABLE_CHARACTER

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class PlayableCharacter
{
protected:
	sf::Sprite sprite;

	float jump_duration;

	bool is_jumping;
	bool is_falling;

	bool left_pressed;
	bool right_pressed;

	float time_this_jump;

	bool just_jumped = false;

private:
	float gravity;

	float speed = 400;

	sf::Vector2f position;

	sf::FloatRect feet;
	sf::FloatRect head;
	sf::FloatRect right;
	sf::FloatRect left;

	sf::Texture texture;

public:
	void spawn(sf::Vector2f start_position, float gravity);

	bool virtual handle_input() = 0;

	sf::FloatRect get_position();

	sf::FloatRect get_feet();
	sf::FloatRect get_head();
	sf::FloatRect get_right();
	sf::FloatRect get_left();

	sf::Sprite get_sprite();

	void stop_falling(float position);
	void stop_right(float position);
	void stop_left(float position);
	void stop_jump();

	sf::Vector2f get_center();

	void update(float elapsed_time);
};

#endif
