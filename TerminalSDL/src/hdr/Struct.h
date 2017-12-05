#ifndef DEF_ICE_STRUCT
#define DEF_ICE_STRUCT 

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Box.h"
#include <string>
#include "Color.h"

typedef struct {

	int exist;
	int w;
	int h;
	SDL_Texture* handle;

} Texture;

typedef struct
{
	int posx, posy;

	std::string TextActual;
	std::string TextLast;
	Color ColorActual;
	Color ColorLast;
	int SizeActual;
	int SizeLast;
	bool HaveTexture;
	Texture cache;

} Label;

typedef struct
{

	Box box;
	Color background;
	Color border;
	int border_size;
	bool isVisible;
	Label LabelActual;

} WritableArea;

typedef struct {

bool quit;

////////////////////////////////////
// Window

bool focus;
int sizew;
int sizeh;

// Clavier

bool key[1024];
std::string command;

////////////////////////////////////
// Souris

int mousex;
int mousey;

	// Clic

bool leftclic;
int leftclic_position_x;
int leftclic_position_y;

bool rightclic;
int rightclic_position_x;
int rightclic_position_y;

	// Mouse Wheel

int wheelup;
int wheeldown;

////////////////////////////////////
// Fichier

char *filedrop;

} Input;

#endif
