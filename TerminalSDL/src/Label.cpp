#include "hdr/Label.h"

extern Core core;

void LabelUpdateTexture(Label* label)
{
	SDL_Surface *surf = TTF_RenderText_Blended(core.GetFont().GetSize(label->SizeActual), label->TextActual.c_str(), label->ColorActual.sdl());
	if (surf)
	{
		Texture texture = { 0 };
		texture.handle = SDL_CreateTextureFromSurface(core.GetRender(), surf);
		texture.w = surf->w; texture.h = surf->h;
		if (label->cache.exist)
		{
			SDL_DestroyTexture(label->cache.handle);
		}
		label->cache = texture;
		label->cache.exist = true;
		label->HaveTexture = true;
		SDL_FreeSurface(surf);
	}
	else
	{
		label->HaveTexture = false;
		label->cache.w = 0;
		label->cache.h = 0;
	}
}

void LabelDraw(Label* label)
{
	if
		(
			label->TextActual != label->TextLast ||
			label->SizeActual != label->SizeLast ||
			label->ColorActual != label->ColorLast
			)
	{
		LabelUpdateTexture(label);
		label->ColorLast = label->ColorActual;
		label->SizeLast = label->SizeActual;
		label->TextLast = label->TextActual;
	}
	Box box = Box
	(
		label->posx,
		label->posy,
		label->cache.w,
		label->cache.h
	);

	if (label->HaveTexture)
		TextureRender(&label->cache, nullptr, &box);
}