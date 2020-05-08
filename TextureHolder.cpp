#include "TextureHolder.hpp"

TextureHolder* TextureHolder::instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(instance == nullptr);
	instance = this;
}

sf::Texture& TextureHolder::get_texture(std::string const &filename) 
{
	auto& m = instance->textures;
	auto key_value_pair = m.find(filename);
	
	if (key_value_pair != m.end()) {
		return key_value_pair->second;
	}
	else
	{
		auto& texture = m[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

