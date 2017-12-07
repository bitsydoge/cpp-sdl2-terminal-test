#pragma once

#include <SDL2/SDL.h>
#include "Box.h"

class Texture{

	int exist_ = 0;
	int w_ = 0;
	int h_ = 0;
	SDL_Texture* handle_ = nullptr;

public:
	int RenderCentered(Box* src, Box* dst);
	int Render(Box* src, Box* dst);

	void SetWidth(int w);
	void SetHeight(int h);

	int GetWidth() const;
	int GetHeight() const;

	void CleanHandle() const;

	void SetExistState(bool state);
	bool Exist() const;

	Texture& operator=(SDL_Texture * texture);
} ;