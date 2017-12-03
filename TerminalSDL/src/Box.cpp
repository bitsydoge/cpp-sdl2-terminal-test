#include "hdr/Box.h"

/*

/// iceBox to SDL_Rect
Box ConvertSdlToBox(SDL_Rect *rect)
{
	Box ice = { 0 };
	if (rect)
		ice.x = rect->x, ice.y = rect->y, ice.w = rect->w, ice.h = rect->h;
	return ice;
}
/// SDL_Rect to iceBox
SDL_Rect ConvertBoxToSdl(Box *rect)
{
	SDL_Rect sdl = { 0 };
	if (rect)
		sdl.x = rect->x, sdl.y = rect->y, sdl.w = rect->w, sdl.h = rect->h;
	return sdl;
}

// Creation
Box BoxNew(int x, int y, int w, int h) {
	Box box = { x,y,w,h };
	return box;
}

// Math
Box BoxScale(Box rect, float scale)
{
	return BoxNew((int)(rect.x * scale), (int)(rect.y * scale), (int)(rect.w * scale), (int)(rect.h * scale));
}

bool BoxCompare(Box box1, Box box2)
{
	if (box1.x != box2.x ||
		box1.y != box2.y ||
		box1.w != box2.w ||
		box1.h != box2.h)
		return false;
	return true;
}

bool BoxCompareSize(Box box1, Box box2)
{
	if (box1.w != box2.w ||
		box1.h != box2.h)
		return false;
	return true;
}

bool BoxComparePos(Box box1, Box box2)
{
	if (box1.x != box2.x ||
		box1.y != box2.y)
		return false;
	return true;
}

// Edit
void BoxSetPos(Box *rect, int x, int y)

void BoxSetSize(Box *rect, int w, int h)

void BoxShift(Box *rect, int x, int y)


*/

Box::Box(const int x = 0, const int y = 0, const int w = 0, const int h = 0) : x_(x), y_(y), w_(w), h_(h)
{

}

SDL_Rect Box::sdl()
{
	return SDL_Rect{x_,y_,w_,h_};
}

void Box::BoxSetPos(int x, int y)
{
	x_ = x; y_ = y;
}

void Box::BoxShift(int x, int y)
{
	x_ += x; y_ += y;
}

void Box::BoxSetSize(int w, int h)
{
	w_ = w; h_ = h;
}

bool Box::operator==(const Box& b) const
{
	if(x_ == b.x_ && y_ == b.y_ && w_ == b.w_ && b.h_)
	{
		return true;
	}
	return false;
}

bool Box::operator!=(const Box& b) const
{
	if (x_ == b.x_ && y_ == b.y_ && w_ == b.w_ && b.h_)
	{
		return false;
	}
	return true;
}

Box Box::operator*(const float& f) const
{
	return Box(x_, y_, w_*f, h_*f);
}

Box& Box::operator=(const SDL_Rect& r)
{
	x_ = r.x; y_ = r.y; w_ = r.w; 
	return *this;
}
