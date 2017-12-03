#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#include <SDL2/SDL.h>
#include "Box.h"
#include "Struct.h"

int TextureRenderCentered(Texture *texture, Box* src, Box* dst);
int TextureRender(Texture *texture, Box* src, Box* dst);

#endif