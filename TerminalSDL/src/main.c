#include "hdr/Input.h"
#include "hdr/Box.h"
#include "hdr/Color.h"


#define DEFAULT_W_SIZE 1280
#define DEFAULT_H_SIZE 720

Core *core;

Core* InitCore()
{
	Core *core = (Core*)malloc(sizeof(Core));
	memset(core, 0, sizeof(Core));
	core->window = SDL_CreateWindow(
		"Title",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		DEFAULT_W_SIZE,
		DEFAULT_H_SIZE,
		SDL_WINDOW_OPENGL | SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_RESIZABLE);
	core->render = SDL_CreateRenderer(core->window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(core->render, 0, 0, 0, 255);
	return core;
}

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
		core->render, 
		ColorRed(wa->background), 
		ColorGreen(wa->background), 
		ColorBlue(wa->background),
	    ColorAlpha(wa->background)
	);
	SDL_Rect sdl = ConvertBoxToSdl(&wa->box);
	SDL_RenderFillRect(core->render, &sdl);
	SDL_SetRenderDrawColor(
		core->render,
		ColorRed(wa->border),
		ColorGreen(wa->border),
		ColorBlue(wa->border),
		ColorAlpha(wa->border)
	);
	for(int i = 0; i<wa->border_size;i++)
	{
		SDL_RenderDrawRect(core->render, &sdl);
		sdl.w -= 2;
		sdl.h -= 2;
		sdl.x++;
		sdl.y++;
	}
};

#ifdef main
#undef main
#endif

int main(int argc, char *argv[]) {
	
	core = InitCore();
	WritableArea *text_zone = WritableAreaCreate();
	WritableAreaSetBox(text_zone, BoxNew(40,40,200,200));
	WritableAreaSetBgColor(text_zone, ColorNew(20, 200, 20));
	WritableAreaSetBorderColor(text_zone, ColorNew(255, 255, 255));
	WritableAreaSetBorderSize(text_zone, 20);


	while(!core->input.quit)
	{
		InputReturn(core);
		SDL_SetRenderDrawColor(
			core->render, 0, 0, 0, 255);
		SDL_RenderClear(core->render);
		WritableAreaDraw(text_zone);
		SDL_RenderPresent(core->render);
	}


	return 0;
}