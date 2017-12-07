#include "hdr/Box.h"
#include "hdr/Color.h"
#include "hdr/Core.h"
#include "hdr/WritableArea.h"

Core core("Terminal", 600, 400);

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
			core.InputReset();
		}
	}
}

int main(int argc, char *argv[]) {
	
	core.GetFont().Load("res/ttf/FiraSans-Medium.ttf");
	core.GetInput().command = "";

	WritableArea text_zone;
	text_zone.SetBox(Box(0, core.GetInput().sizeh - 40, core.GetInput().sizew, 40));
	text_zone.SetBgColor(Color(20, 20, 20));
	text_zone.SetBorderColor(Color(55, 55, 55));
	text_zone.SetBorderSize(5);

	WritableArea rectangle;
	rectangle.SetBox(Box(0, 0, core.GetInput().sizew, core.GetInput().sizeh));
	rectangle.SetBgColor(Color(20, 20, 20));
	rectangle.SetBorderColor(Color(55, 55, 55));
	rectangle.SetBorderSize(5);

	WritableArea title_bar;
	title_bar.SetBox(Box(0, 0, core.GetInput().sizew, 20));
	title_bar.SetBgColor(Color(55, 55, 55));
	title_bar.SetBorderColor(Color(55, 55, 55));
	title_bar.SetBorderSize(0);

	Label minus;
	minus = Box(10, core.GetInput().sizeh-30,0,0);
	minus = 18;
	minus = Color(250, 250, 250);
	minus = "> ";
	minus.UpdateTexture();

	Label command;
	command = Box(10 + minus.GetWidth(), core.GetInput().sizeh - 30,0,0);
	command = 15;
	command = Color(250, 250, 250);
	command = core.GetInput().command;
	command.UpdateTexture();

	Label bar;
	bar = Box(10, core.GetInput().sizeh - 30,0,0);
	bar = 18;
	bar = Color(250, 250, 250);
	bar = "|";
	bar.UpdateTexture();

	Label win_option;
	win_option = Box(core.GetInput().sizew - 30, -1,0,0);
	win_option = 18;
	win_option = Color(250, 250, 250);
	win_option = "- x";
	win_option.UpdateTexture();

	while(!core.GetInput().quit)
	{
		// Input Return
		core.InputReturn();
		// Window Command
		WindowCommand();
		// Writing
		text_zone.Input();
		command.SetText(core.GetInput().command);

		// Render Clear
		SDL_SetRenderDrawColor(core.GetRender(), 10, 10, 10, 255);
		SDL_RenderClear(core.GetRender());
		
		// WritableArea
		rectangle.Draw();
		title_bar.Draw();
		text_zone.Draw();
		
		// Labels
		minus.Draw();
		command.Draw();
		bar.SetPosX(10 + command.GetWidth() + minus.GetWidth()-4);
		bar.Draw();
		win_option.Draw();

		// Render everything
		SDL_RenderPresent(core.GetRender());
	}
	return 0;
}