
#ifndef __BOB_HPP
#define __BOB_HPP

#include "PlayableCharacter.hpp"

class Bob : public PlayableCharacter
{
public:
	Bob();

	bool virtual handle_input();
};

#endif
