#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <sstream>

void Engine::update(float dt_seconds)
{

  if (playing)
  {
    time_remaining -= dt_seconds;
    if (time_remaining <= 0)
    {
      new_level_required = true;
    }
  }
}