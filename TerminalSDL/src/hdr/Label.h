#pragma once
#include "Texture.h"
#include "Color.h"
#include "hdr/Core.h"

typedef struct
{
	int posx, posy;

	std::string TextActual;
	std::string TextLast;
	Color ColorActual;
	Color ColorLast;
	int SizeActual;
	int SizeLast;
	bool HaveTexture;
	Texture cache;

} Label;

void LabelUpdateTexture(Label* label);
void LabelDraw(Label* label);