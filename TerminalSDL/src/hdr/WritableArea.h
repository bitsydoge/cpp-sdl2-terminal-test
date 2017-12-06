#pragma once
#include "Box.h"
#include "Color.h"
#include "Label.h"
#include <iostream>

typedef struct
{

	Box box;
	Color background;
	Color border;
	int border_size;
	bool isVisible;
	Label LabelActual;

} WritableArea;

WritableArea* WritableAreaCreate();

void WritableAreaSetBox(WritableArea* wa, Box box);

void WritableAreaSetBgColor(WritableArea* wa, Color color);

void WritableAreaSetBorderColor(WritableArea* wa, Color color);

void WritableAreaSetBorderSize(WritableArea* wa, int size);

void WritableAreaDraw(WritableArea* wa);

void WritableAreaInput(Label *label);