#include "hdr/Label.h"

extern Core core;

Label::Label()
{
	posx_ = 0, posy_ = 0;
	TextActual_ = "";
	TextLast_ = "";
	ColorActual_ = Color(255,255,255);
	ColorLast_ = Color(255, 255, 255);
	SizeActual_ = 12;
	SizeLast_ = 12;
	HaveTexture_ = false;
	Texture cache_;
}

void Label::UpdateTexture()
{
	SDL_Surface *surf = TTF_RenderText_Blended(core.GetFont().GetSize(SizeActual_), TextActual_.c_str(), ColorActual_.sdl());
	if (surf)
	{
		Texture texture;
		texture = SDL_CreateTextureFromSurface(core.GetRender(), surf);
		texture.SetWidth(surf->w); 
		texture.SetHeight(surf->h);

		if (cache_.Exist())
		{
			cache_.CleanHandle();
		}
		cache_ = texture;
		cache_.SetExistState(true);
		HaveTexture_ = true;
		SDL_FreeSurface(surf);
	}
	else
	{
		HaveTexture_ = false;
		cache_.SetWidth(0);
		cache_.SetHeight(0);
	}
}

void Label::Draw()
{
	if
		(
			TextActual_ != TextLast_ ||
			SizeActual_ != SizeLast_ ||
			ColorActual_ != ColorLast_
			)
	{
		UpdateTexture();
		ColorLast_ = ColorActual_;
		SizeLast_ = SizeActual_;
		TextLast_ = TextActual_;
	}
	Box box = Box
	(
		posx_,
		posy_,
		cache_.GetWidth(),
		cache_.GetHeight()
	);

	if (HaveTexture_)
		cache_.Render(nullptr, &box);
}

void Label::SetPos(int x, int y)
{
	posx_ = x; posy_ = y;
}

void Label::SetPosX(int x)
{
	posx_ = x;
}

void Label::SetPosY(int y)
{
	posy_ = y;
}

void Label::SetColor(Color color) {
	ColorActual_ = color;
}

void Label::SetSize(int size)
{
	SizeActual_ = size;
}

void Label::SetText(std::string text)
{
	TextActual_ = text;
}

int Label::GetWidth() const
{
	return cache_.GetWidth();
}

int Label::GetHeight() const
{
	return cache_.GetHeight();
}

Label& Label::operator=(const Color& color)
{
	ColorActual_ = color;
	return *this;
}

Label& Label::operator=(const std::string& text)
{
	TextActual_ = text;
	return *this;
}

Label& Label::operator=(const int& size)
{
	SizeActual_ = size;
	return *this;
}

Label& Label::operator=(const Box& box)
{
	posx_ = box.GetPosX();
	posy_ = box.GetPosY();
	return *this;
}