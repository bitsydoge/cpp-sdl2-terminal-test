#include "hdr/Input.h"
#include "hdr/Box.h"
#include "hdr/Color.h"
#include <SDL2/SDL_ttf.h>
#include "hdr/Texture.h"
#include <iostream>
#include "hdr/Core.h"

Core core("Terminal", 600, 400);

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
		core.GetRender(),
		ColorRed(wa->background), 
		ColorGreen(wa->background), 
		ColorBlue(wa->background),
	    ColorAlpha(wa->background)
	);
	SDL_Rect sdl = wa->box.sdl();
	SDL_RenderFillRect(core.GetRender(), &sdl);
	SDL_SetRenderDrawColor(
		core.GetRender(),
		ColorRed(wa->border),
		ColorGreen(wa->border),
		ColorBlue(wa->border),
		ColorAlpha(wa->border)
	);
	for(int i = 0; i<wa->border_size;i++)
	{
		SDL_RenderDrawRect(core.GetRender(), &sdl);
		sdl.w -= 2;
		sdl.h -= 2;
		sdl.x++;
		sdl.y++;
	}
};



void LabelUpdateTexture(Label* label)
{
		SDL_Surface *surf = TTF_RenderText_Blended(core.GetFont().GetSize(label->SizeActual), label->TextActual.c_str(), ColorToSdl(label->ColorActual));
		if (surf)
		{
			//printf("Oh My Goodness, an error : %s", TTF_GetError());
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

	if(label->HaveTexture)
		TextureRender(&label->cache, NULL, &box);
}

void WritableAreaInput(Label *label)
{
	if(InputButton(INPUT_BACKSPACE))
	{
		if(core.GetInput().command.size())
		{
			core.GetInput().command.pop_back();
			std::cout << core.GetInput().command << std::endl;
			InputReset();
		}
	}
	if (InputButton(INPUT_RETURN))
	{
		core.GetInput().command = "";
	}
}

void WindowCommand()
{
	if (core.GetInput().leftclic) // WINDOW MOVE
	{
		if(core.GetInput().leftclic_position_y < 20)
		{
			int x_mouse_screen; int y_mouse_screen;
			SDL_GetGlobalMouseState(&x_mouse_screen, &y_mouse_screen);
			SDL_SetWindowPosition(core.GetWindow(), x_mouse_screen - core.GetInput().leftclic_position_x, y_mouse_screen - core.GetInput().leftclic_position_y);
		}
		if (core.GetInput().leftclic_position_x > core.GetInput().sizew - 20 && 
			core.GetInput().leftclic_position_y < 20
		)
			core.GetInput().quit = true;

		if (
			core.GetInput().leftclic_position_x > core.GetInput().sizew - 40 && 
			core.GetInput().leftclic_position_x < core.GetInput().sizew - 20 && 
			core.GetInput().leftclic_position_y < 20
		)
		{
			core.WindowMinimize();
			InputReset();
		}
		

	}
}

int main(int argc, char *argv[]) {
	
	core.GetFont().Load("res/ttf/FiraSans-Medium.ttf");

	WritableArea *text_zone = WritableAreaCreate();
	WritableAreaSetBox(text_zone, Box(0, core.GetInput().sizeh - 40, core.GetInput().sizew, 40));
	WritableAreaSetBgColor(text_zone, ColorNew(20, 20, 20));
	WritableAreaSetBorderColor(text_zone, ColorNew(55, 55, 55));
	WritableAreaSetBorderSize(text_zone, 5);

	WritableArea *rectangle = WritableAreaCreate();
	WritableAreaSetBox(rectangle, Box(0, 0, core.GetInput().sizew, core.GetInput().sizeh));
	WritableAreaSetBgColor(rectangle, ColorNew(20, 20, 20));
	WritableAreaSetBorderColor(rectangle, ColorNew(55, 55, 55));
	WritableAreaSetBorderSize(rectangle, 5);

	WritableArea *title = WritableAreaCreate();
	WritableAreaSetBox(title, Box(0, 0, core.GetInput().sizew, 20));
	WritableAreaSetBgColor(title, ColorNew(55, 55, 55));
	WritableAreaSetBorderColor(title, ColorNew(55, 55, 55));
	WritableAreaSetBorderSize(title, 0);

	Label minus = { 0 };
	minus.posx = 10;
	minus.posy = core.GetInput().sizeh - 30;
	minus.SizeActual = 18;
	minus.ColorActual = ColorNew(250, 250, 250);
	minus.TextActual = "> ";
	minus.TextLast = minus.TextActual;
	LabelUpdateTexture(&minus);

	Label command = { 0 };
	command.posx = 10 + minus.cache.w;
	command.posy = core.GetInput().sizeh - 30;
	command.SizeActual = 15;
	command.ColorActual = ColorNew(250, 250, 250);
	core.GetInput().command = "";
	command.TextActual = core.GetInput().command;
	command.TextLast = command.TextActual;
	LabelUpdateTexture(&command);

	Label bar = { 0 };
	bar.posx = 10;
	bar.posy = core.GetInput().sizeh - 30;
	bar.SizeActual = 18;
	bar.ColorActual = ColorNew(250, 250, 250);
	bar.TextActual = "|";
	bar.TextLast = bar.TextActual;
	LabelUpdateTexture(&bar);

	Label win_option = { 0 };
	win_option.posx = core.GetInput().sizew - 30;
	win_option.posy = -1;
	win_option.SizeActual = 18;
	win_option.ColorActual = ColorNew(250, 250, 250);
	win_option.TextActual = "- x";
	win_option.TextLast = bar.TextActual;
	LabelUpdateTexture(&win_option);
	SDL_Rect rectus = {0,0,40,40};
	SDL_SetTextInputRect(&rectus);
	while(!core.GetInput().quit)
	{
		InputReturn();
		WindowCommand();
		//printf("%s\n", core.GetInput().command);
		WritableAreaInput(&command);
		SDL_SetRenderDrawColor(core.GetRender(), 10, 10, 10, 255);
		command.TextActual = core.GetInput().command;
		SDL_RenderClear(core.GetRender());
		WritableAreaDraw(rectangle);
		WritableAreaDraw(title);
		WritableAreaDraw(text_zone);

		LabelDraw(&minus);
		LabelDraw(&command);
		bar.posx = 10 + command.cache.w + minus.cache.w-4;
		LabelDraw(&bar);
		LabelDraw(&win_option);

		SDL_RenderPresent(core.GetRender());
	}

	return 0;
}