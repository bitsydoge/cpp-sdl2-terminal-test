#ifndef DEF_ICE_BOX
#define DEF_ICE_BOX
#include "hdr/Struct.h"
#include <SDL2/SDL.h>

/// iceBox to SDL_Rect
Box ConvertSdlToBox(SDL_Rect *rect);
/// SDL_Rect to iceBox
SDL_Rect ConvertBoxToSdl(Box *rect);

// Creation
Box BoxNew(int x, int y, int w, int h);

// Math
Box BoxScale(Box rect, float scale);
Bool BoxCompare(Box box1, Box box2);
Bool BoxCompareSize(Box box1, Box box2);
Bool BoxComparePos(Box box1, Box box2);

// Edit
void BoxSetPos(Box *rect, int x, int y);
void BoxSetSize(Box *rect, int w, int h);
void BoxShift(Box *rect, int x, int y);
#endif
