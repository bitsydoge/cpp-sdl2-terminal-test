#pragma once
#include <SDL2/SDL.h>

class Box
{
private:
	int x_, y_, w_, h_;

public:
	Box(int x, int y, int w, int h);
	SDL_Rect sdl();

	// Edit
	void BoxSetPos(int x, int y);
	void BoxSetSize(int w, int h);
	void BoxShift(int x, int y);

	// Overload
	bool operator==(const Box& b) const;
	bool operator!=(const Box& b) const;
	Box operator*(const float& f) const;
	Box& operator=(const SDL_Rect& r);
	

	bool BoxCompareSize(Box box2);
	bool BoxComparePos(Box box2);
};
