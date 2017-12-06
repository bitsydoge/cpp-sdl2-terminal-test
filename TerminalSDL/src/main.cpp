#include "hdr/Box.h"
#include "hdr/Color.h"
#include "hdr/Core.h"
#include "hdr/WritableArea.h"
#include <memory>

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

	WritableArea title;
	title.SetBox(Box(0, 0, core.GetInput().sizew, 20));
	title.SetBgColor(Color(55, 55, 55));
	title.SetBorderColor(Color(55, 55, 55));
	title.SetBorderSize(0);

	Label minus = { 0 };
	minus.posx = 10;
	minus.posy = core.GetInput().sizeh - 30;
	minus.SizeActual = 18;
	minus.ColorActual = Color(250, 250, 250);
	minus.TextActual = "> ";
	minus.TextLast = minus.TextActual;
	LabelUpdateTexture(&minus);

	Label command = { 0 };
	command.posx = 10 + minus.cache.w;
	command.posy = core.GetInput().sizeh - 30;
	command.SizeActual = 15;
	command.ColorActual = Color(250, 250, 250);
	core.GetInput().command = "";
	command.TextActual = core.GetInput().command;
	command.TextLast = command.TextActual;
	LabelUpdateTexture(&command);

	Label bar = { 0 };
	bar.posx = 10;
	bar.posy = core.GetInput().sizeh - 30;
	bar.SizeActual = 18;
	bar.ColorActual = Color(250, 250, 250);
	bar.TextActual = "|";
	bar.TextLast = bar.TextActual;
	LabelUpdateTexture(&bar);

	Label win_option = { 0 };
	win_option.posx = core.GetInput().sizew - 30;
	win_option.posy = -1;
	win_option.SizeActual = 18;
	win_option.ColorActual = Color(250, 250, 250);
	win_option.TextActual = "- x";
	win_option.TextLast = bar.TextActual;
	LabelUpdateTexture(&win_option);
	SDL_Rect rectus = {0,0,40,40};
	SDL_SetTextInputRect(&rectus);
	while(!core.GetInput().quit)
	{
		core.InputReturn();
		WindowCommand();
		//printf("%s\n", core.GetInput().command);
		text_zone.Input();
		SDL_SetRenderDrawColor(core.GetRender(), 10, 10, 10, 255);
		command.TextActual = core.GetInput().command;
		SDL_RenderClear(core.GetRender());
		
		rectangle.Draw();
		title.Draw();
		text_zone.Draw();

		LabelDraw(&minus);
		LabelDraw(&command);

		bar.posx = 10 + command.cache.w + minus.cache.w-4;
		LabelDraw(&bar);
		LabelDraw(&win_option);
		SDL_RenderPresent(core.GetRender());
	}
	return 0;
}