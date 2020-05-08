#ifndef __TEXTURE_HOLDER_H
#define __TEXTURE_HOLDER_H

#include <map>
#include <SFML/Graphics/Texture.hpp>

class TextureHolder
{
private:
	std::map<std::string, sf::Texture> textures;
	static TextureHolder *instance;

public:
	TextureHolder();
	static sf::Texture &get_texture(std::string const &filename);
};

#endif
