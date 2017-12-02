#ifndef DEF_ICE_STRUCT
#define DEF_ICE_STRUCT 

#define False 0
#define True 1
#define Error -1

#include <SDL2/SDL.h>

typedef char Bool;
typedef Uint32 Color;
typedef char* String;

typedef struct
{
	int x, y, w, h;
} Box;

typedef struct
{
	Box box;
	Color background;
	Color border;
	Bool isVisible;

} WritableArea;

typedef struct
{
	SDL_Texture *texture;
	Box box;

	String Title;
	Bool haveTitle;
	Bool isVisible;
	Bool isFocused;

} GuiWindow;

typedef struct {

Bool quit;

////////////////////////////////////
// Window

Bool focus;
int sizew;
int sizeh;

// Clavier

Bool key[1024];

////////////////////////////////////
// Souris

int mousex;
int mousey;

	// Clic

Bool leftclic;
int leftclic_position_x;
int leftclic_position_y;

Bool rightclic;
int rightclic_position_x;
int rightclic_position_y;

	// Mouse Wheel

int wheelup;
int wheeldown;

////////////////////////////////////
// Fichier

char *filedrop;

} Input;

typedef struct
{
	SDL_Window *window;
	SDL_Renderer *render;
	Input input;

	int GuiWindowManager_Size;
	GuiWindow * GuiWindoManager;

} Core;

#endif
