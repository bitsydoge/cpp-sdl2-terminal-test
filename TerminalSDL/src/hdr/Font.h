#pragma once
#include <string>
#include <SDL2/SDL_ttf.h>

class Font
{
private:
	TTF_Font *font[256];

public:
	Font();
	void Load(std::string path);
	TTF_Font *GetSize(int x);
};
