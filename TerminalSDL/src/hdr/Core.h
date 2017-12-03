#pragma once
#include "Input.h"
#include "Font.h"

class Core
{
	private:
		SDL_Window *window;
		SDL_Renderer *render;
		Input input;
		Font font;

	public:
		Core(std::string title, int x, int y);
		SDL_Renderer *GetRender() const;
		SDL_Window *GetWindow() const;
		Font& GetFont();
		Input& GetInput();
		void WindowMinimize() const;
		void Quit();
};
