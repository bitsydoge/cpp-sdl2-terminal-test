#pragma once
#include <SDL2/SDL.h>

class Box
{
private:
	int x_, y_, w_, h_;

public:
	Box();
	Box(int x, int y, int w, int h);
	SDL_Rect sdl() const;

	int GetPosX() const;
	int GetPosY() const;
	int GetPosW() const;
	int GetPosH() const;

	// Edit
	void SetPos(int x, int y);
	void SetSize(int w, int h);
	void ShiftPos(int x, int y);

	// Overload
	bool operator==(const Box& b) const;
	bool operator!=(const Box& b) const;
	Box operator*(const float& f) const;
	Box& operator=(const SDL_Rect& r);
};