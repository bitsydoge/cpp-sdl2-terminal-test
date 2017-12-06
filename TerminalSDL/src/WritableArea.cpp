#include "hdr/WritableArea.h"

extern Core core;

WritableArea::WritableArea()
{

}


void WritableArea::SetBox(Box box)
{
	box_ = box;
}

void WritableArea::SetBgColor(Color color)
{
	background_ = color;
}

void WritableArea::SetBorderColor(Color color)
{
	border_ = color;
}

void WritableArea::SetBorderSize(int size)
{
	border_size_ = size;
}

void WritableArea::Draw()
{
	SDL_SetRenderDrawColor(
		core.GetRender(), background_.Red(),
		background_.Green(),
		background_.Blue(),
		background_.Alpha()
	);
	SDL_Rect sdl = box_.sdl();
	SDL_RenderFillRect(core.GetRender(), &sdl);
	SDL_SetRenderDrawColor(
		core.GetRender(),
		border_.Red(),
		border_.Green(),
		border_.Blue(),
		border_.Alpha());
	for (int i = 0; i<border_size_; i++)
	{
		SDL_RenderDrawRect(core.GetRender(), &sdl);
		sdl.w -= 2;
		sdl.h -= 2;
		sdl.x++;
		sdl.y++;
	}
};


void WritableArea::Input()
{
	if (core.InputButton(INPUT_BACKSPACE))
	{
		if (core.GetInput().command.size())
		{
			core.GetInput().command.pop_back();
			std::cout << core.GetInput().command << std::endl;
			core.InputReset();
		}
	}
	if (core.InputButton(INPUT_RETURN))
	{
		core.GetInput().command = "";
	}
}