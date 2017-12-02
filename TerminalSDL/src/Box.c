#include "hdr/Box.h"

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

Bool BoxCompare(Box box1, Box box2)
{
	if (box1.x != box2.x ||
		box1.y != box2.y ||
		box1.w != box2.w ||
		box1.h != box2.h)
		return False;
	return True;
}

Bool BoxCompareSize(Box box1, Box box2)
{
	if (box1.w != box2.w ||
		box1.h != box2.h)
		return False;
	return True;
}

Bool BoxComparePos(Box box1, Box box2)
{
	if (box1.x != box2.x ||
		box1.y != box2.y)
		return False;
	return True;
}

// Edit
void BoxSetPos(Box *rect, int x, int y)
{
	rect->x = x; rect->y = y;
}
void BoxSetSize(Box *rect, int w, int h)
{
	rect->w = w; rect->h = h;
}
void BoxShift(Box *rect, int x, int y)
{
	rect->x += x; rect->y += y;
}