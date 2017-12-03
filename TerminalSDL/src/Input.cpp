#include "hdr/Input.h"
#include <iostream>
#include <stdio.h>
#include "hdr/Core.h"

extern Core core;

int InputReturn()
{
	static SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_TEXTINPUT:
			core.GetInput().command = core.GetInput().command + std::string(event.text.text);
			break;
		case SDL_QUIT:
			core.GetInput().quit = 1;
			break;
		case SDL_KEYDOWN:
			core.GetInput().key[event.key.keysym.scancode] = 1;
			break;
		case SDL_KEYUP:
			core.GetInput().key[event.key.keysym.scancode] = 0;
			break;
		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
				core.GetInput().wheelup = 1;
			if (event.wheel.y < 0)
				core.GetInput().wheeldown = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				core.GetInput().leftclic = 1;
				core.GetInput().leftclic_position_x = event.motion.x;
				core.GetInput().leftclic_position_y = event.motion.y;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				core.GetInput().rightclic = 1;
				core.GetInput().rightclic_position_x = event.motion.x;
				core.GetInput().rightclic_position_y = event.motion.y;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				core.GetInput().leftclic = 0;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				core.GetInput().rightclic = 0;
			}
			break;
		case SDL_MOUSEMOTION:
			core.GetInput().mousex = event.motion.x;
			core.GetInput().mousey = event.motion.y;
			break;
		case SDL_DROPFILE:
			core.GetInput().filedrop = event.drop.file;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				core.GetInput().focus = 1;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				core.GetInput().focus = 0;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				SDL_GetWindowSize(core.GetWindow(), &core.GetInput().sizew, &core.GetInput().sizeh);
				break;
			default:
				break;
			}
		default:
			break;
		}
		if (event.wheel.y == 0)
		{
			core.GetInput().wheelup = 0;
			core.GetInput().wheeldown = 0;
		}
	}
	return 0;
}

void InputReset(){
	memset(&core.GetInput().key, 0, sizeof(bool[1024]));
	memset(&core.GetInput().leftclic, 0, sizeof(bool));
}

bool InputButton(const int button)
{
	if(button < 512)
	{
		return core.GetInput().key[button];
	}
	if(button > 600)
	{
		if(button == INPUT_LEFTCLICK)
		{
			return core.GetInput().leftclic;
		}
		if (button == INPUT_RIGHTCLICK)
		{
			return core.GetInput().rightclic;
		}
		if (button == INPUT_WHEELUP)
		{
			return core.GetInput().wheelup;
		}
		if (button == INPUT_WHEELDOWN)
		{
			return core.GetInput().wheeldown;
		}
	}
	printf("No key have that name");
	return false;
}
