#include "hdr/WritableArea.h"

extern Core core;

WritableArea* WritableAreaCreate()
{
	WritableArea* writable_area = (WritableArea*)malloc(sizeof(WritableArea));
	memset(writable_area, 0, sizeof(WritableArea));
	return writable_area;
}

void WritableAreaSetBox(WritableArea* wa, Box box)
{
	wa->box = box;
}

void WritableAreaSetBgColor(WritableArea* wa, Color color)
{
	wa->background = color;
}

void WritableAreaSetBorderColor(WritableArea* wa, Color color)
{
	wa->border = color;
}

void WritableAreaSetBorderSize(WritableArea* wa, int size)
{
	wa->border_size = size;
}

void WritableAreaDraw(WritableArea* wa)
{
	SDL_SetRenderDrawColor(
		core.GetRender(), wa->background.Red(),
		wa->background.Green(),
		wa->background.Blue(),
		wa->background.Alpha()
	);
	SDL_Rect sdl = wa->box.sdl();
	SDL_RenderFillRect(core.GetRender(), &sdl);
	SDL_SetRenderDrawColor(
		core.GetRender(),
		wa->border.Red(),
		wa->border.Green(),
		wa->border.Blue(),
		wa->border.Alpha());
	for (int i = 0; i<wa->border_size; i++)
	{
		SDL_RenderDrawRect(core.GetRender(), &sdl);
		sdl.w -= 2;
		sdl.h -= 2;
		sdl.x++;
		sdl.y++;
	}
};


void WritableAreaInput(Label *label)
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


