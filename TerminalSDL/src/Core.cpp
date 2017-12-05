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

void Core::InputReturn()
{
	static SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_TEXTINPUT:
			GetInput().command = GetInput().command + std::string(event.text.text);
			break;
		case SDL_QUIT:
			GetInput().quit = 1;
			break;
		case SDL_KEYDOWN:
			GetInput().key[event.key.keysym.scancode] = 1;
			break;
		case SDL_KEYUP:
			GetInput().key[event.key.keysym.scancode] = 0;
			break;
		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
				GetInput().wheelup = 1;
			if (event.wheel.y < 0)
				GetInput().wheeldown = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				GetInput().leftclic = 1;
				GetInput().leftclic_position_x = event.motion.x;
				GetInput().leftclic_position_y = event.motion.y;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				GetInput().rightclic = 1;
				GetInput().rightclic_position_x = event.motion.x;
				GetInput().rightclic_position_y = event.motion.y;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				GetInput().leftclic = 0;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				GetInput().rightclic = 0;
			}
			break;
		case SDL_MOUSEMOTION:
			GetInput().mousex = event.motion.x;
			GetInput().mousey = event.motion.y;
			break;
		case SDL_DROPFILE:
			GetInput().filedrop = event.drop.file;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				GetInput().focus = 1;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				GetInput().focus = 0;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				SDL_GetWindowSize(GetWindow(), &GetInput().sizew, &GetInput().sizeh);
				break;
			default:
				break;
			}
		default:
			break;
		}
		if (event.wheel.y == 0)
		{
			GetInput().wheelup = 0;
			GetInput().wheeldown = 0;
		}
	}
}

void Core::InputReset() {
	memset(&GetInput().key, 0, sizeof(bool[1024]));
	memset(&GetInput().leftclic, 0, sizeof(bool));
}

bool Core::InputButton(const int button)
{
	if (button < 512)
	{
		return GetInput().key[button];
	}
	if (button > 600)
	{
		if (button == INPUT_LEFTCLICK)
		{
			return GetInput().leftclic;
		}
		if (button == INPUT_RIGHTCLICK)
		{
			return GetInput().rightclic;
		}
		if (button == INPUT_WHEELUP)
		{
			return GetInput().wheelup;
		}
		if (button == INPUT_WHEELDOWN)
		{
			return GetInput().wheeldown;
		}
	}
	printf("No key have that name");
	return false;
}