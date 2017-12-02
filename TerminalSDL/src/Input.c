#include "hdr/Input.h"

int InputReturn(Core *core)
{
	static SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			core->input.quit = 1;
			break;
		case SDL_KEYDOWN:
			core->input.key[event.key.keysym.scancode] = 1;
			break;
		case SDL_KEYUP:
			core->input.key[event.key.keysym.scancode] = 0;
			break;
		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
				core->input.wheelup = 1;
			if (event.wheel.y < 0)
				core->input.wheeldown = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				core->input.leftclic = 1;
				core->input.leftclic_position_x = event.motion.x;
				core->input.leftclic_position_y = event.motion.y;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				core->input.rightclic = 1;
				core->input.rightclic_position_x = event.motion.x;
				core->input.rightclic_position_y = event.motion.y;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				core->input.leftclic = 0;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				core->input.rightclic = 0;
			}
			break;
		case SDL_MOUSEMOTION:
			core->input.mousex = event.motion.x;
			core->input.mousey = event.motion.y;
			break;
		case SDL_DROPFILE:
			core->input.filedrop = event.drop.file;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				core->input.focus = 1;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				core->input.focus = 0;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				SDL_GetWindowSize(core->window, &core->input.sizew, &core->input.sizew);
				break;
			default:
				break;
			}
		default:
			break;
		}
		if (event.wheel.y == 0)
		{
			core->input.wheelup = 0;
			core->input.wheeldown = 0;
		}
	}
	return 0;
}

void InputReset(Core *core){
	int temp = core->input.focus;
	int temp2 = core->input.quit;
	int mousex = core->input.mousex;
	int mousey = core->input.mousey;
	memset(&core->input, 0, sizeof(Input));
	core->input.focus = temp;
	core->input.quit = temp2;
	core->input.mousex = mousex;
	core->input.mousey = mousey;
}

Bool InputButton(Core *core, int button)
{
	if(button < 512)
	{
		return core->input.key[button];
	}
	if(button > 600)
	{
		if(button == INPUT_LEFTCLICK)
		{
			return core->input.leftclic;
		}
		if (button == INPUT_RIGHTCLICK)
		{
			return core->input.rightclic;
		}
		if (button == INPUT_WHEELUP)
		{
			return core->input.wheelup;
		}
		if (button == INPUT_WHEELDOWN)
		{
			return core->input.wheeldown;
		}
	}
	printf("No key have that name");
	return False;
}
