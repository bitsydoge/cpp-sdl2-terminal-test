#include "hdr/Color.h"

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r_(r), g_(g), b_(b), a_(a){}

SDL_Color Color::sdl()
{
	SDL_Color sdl = { r_, g_, b_, a_ };
	return sdl;
}

uint8_t Color::Red()
{
	return r_;
}

uint8_t Color::Green()
{
	return g_;
}

uint8_t Color::Blue()
{
	return b_;
}

uint8_t Color::Alpha()
{
	return a_;
}

bool Color::operator==(const Color& c) const
{
	if (r_ == c.r_ && g_ == c.g_ && b_ == c.b_ && a_ && c.a_)
	{
		return true;
	}
	return false;
}

bool Color::operator!=(const Color& c) const
{
	if (r_ == c.r_ && g_ == c.g_ && b_ == c.b_ && a_ && c.a_)
	{
		return false;
	}
	return true;
}

Color& Color::operator=(const SDL_Color& c)
{
	r_ = c.r; g_ = c.g; b_ = c.b; a_ = c.a;
	return *this;
}
