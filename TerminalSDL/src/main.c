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

void WritableAreaDraw(WritableArea* wa)
{
	SDL_SetRenderDrawColor(core->render, ColorRed(wa->background), ColorGreen(wa->background), ColorBlue(wa->background),
	                       ColorAlpha(wa->background));
	SDL_Rect sdl = ConvertBoxToSdl(&wa->box);
	SDL_RenderDrawRect(core->render, &sdl);
};

#ifdef main
#undef main
#endif


int main(int argc, char *argv[]) {
	
	core = InitCore();
	WritableArea *text_zone = WritableAreaCreate();
	WritableAreaSetBox(text_zone, BoxNew(0,0,200,200));

	while(!core->input.quit)
	{
		InputReturn(core);
		WritableAreaDraw(text_zone);
		SDL_RenderClear(core->render);
		SDL_RenderPresent(core->render);
	}
	return 0;
}