#ifndef DEF_ICE_COLOR
#define DEF_ICE_COLOR 

#include <SDL2/SDL.h>
#include "Input.h"

Color ColorNew(const unsigned int r, const unsigned int g, const unsigned int b);

Color ColorANew(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a);
SDL_Color ColorToSdl(Color color);

int ColorRed(Color color);

int ColorGreen(Color color);

int ColorBlue(Color color);

int ColorAlpha(Color color);

#endif
