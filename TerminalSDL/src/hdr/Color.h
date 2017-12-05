#ifndef DEF_ICE_COLOR
#define DEF_ICE_COLOR 

#include <SDL2/SDL.h>

class Color
{
	private:
		uint8_t r_, g_, b_, a_;
	public:
	Color(uint8_t r = 255, uint8_t g = 255, uint8_t b = 255, uint8_t a = 255);
	SDL_Color sdl();
	uint8_t Red();
	uint8_t Green();
	uint8_t Blue();
	uint8_t Alpha();
	bool operator==(const Color& c) const;
	bool operator!=(const Color& c) const;
	Color& Color::operator=(const SDL_Color& c);
};

#endif
