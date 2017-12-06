#pragma once

#include <SDL2/SDL.h>
#include "Box.h"

typedef struct {

	int exist;
	int w;
	int h;
	SDL_Texture* handle;

} Texture;

int TextureRenderCentered(Texture *texture, Box* src, Box* dst);
int TextureRender(Texture *texture, Box* src, Box* dst);