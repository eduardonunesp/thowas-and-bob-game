
#ifndef __THOMAS_HPP
#define __THOMAS_HPP

#include "PlayableCharacter.hpp"

class Thomas : public PlayableCharacter
{
public:
	Thomas();

	bool virtual handle_input();
};

#endif // __THOMAS_HPP
