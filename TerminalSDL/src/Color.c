#include "hdr/Color.h"

Color ColorNew(const unsigned int r, const unsigned int g, const unsigned int b) {
	return (r << 24) + (g << 16) + (b << 8) + 255;
}

Color ColorANew(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a) {
	return (r << 24) + (g << 16) + (b << 8) + a;
}

SDL_Color ColorToSdl(Color color)
{
	SDL_Color sdl_color = { 0,0,0,255 };
	sdl_color.r = color >> 24 & 255;
	sdl_color.g = color >> 16 & 255;
	sdl_color.b = color >> 8 & 255;
	sdl_color.a = color & 255;
	return sdl_color;
}

int ColorRed(Color color)
{
	SDL_Color color_sdl = ColorToSdl(color);
	return color_sdl.r;
}

int ColorGreen(Color color)
{
	SDL_Color color_sdl = ColorToSdl(color);
	return color_sdl.g;
}

int ColorBlue(Color color)
{
	SDL_Color color_sdl = ColorToSdl(color);
	return color_sdl.b;
}

int ColorAlpha(Color color)
{
	SDL_Color color_sdl = ColorToSdl(color);
	return color_sdl.a;
}