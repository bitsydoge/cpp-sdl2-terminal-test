#include "hdr/Core.h"

Core::Core(std::string title, int w, int h)
{
	TTF_Init();
	window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		w,
		h,
		SDL_WINDOW_OPENGL | SDL_RENDERER_PRESENTVSYNC | SDL_WINDOW_BORDERLESS);
	SDL_SetWindowOpacity(window, 0.9f);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	input.sizew = w;
	input.sizeh = h;
	SDL_StartTextInput();
}

SDL_Renderer* Core::GetRender() const
{
	return render;
}

SDL_Window* Core::GetWindow() const
{
	return window;
}

Font& Core::GetFont()
{
	return font;
}

Input& Core::GetInput()
{
	return input;
}

void Core::WindowMinimize() const
{
	SDL_MinimizeWindow(window);
}

void Core::Quit()
{
	GetInput().quit = true;
}
