
#ifndef __BOB_HPP
#define __BOB_HPP

#include "PlayableCharacter.hpp"

class Bob : public PlayableCharacter
{
public:
	// A constructor specific to Bob
	Bob();

	// The overriden input handler for Bob
	bool virtual handle_input();

};

#endif // __BOB_HPP
