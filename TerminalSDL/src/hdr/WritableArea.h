#pragma once
#include "Box.h"
#include "Color.h"
#include "Label.h"
#include <iostream>

class WritableArea
{
	Box box_;
	Label LabelActual_;
	Color background_;
	Color border_;
	int border_size_;
	bool isVisible_;

	public:

	WritableArea();
	void SetBox(Box box);
	void SetBgColor(Color color);
	void SetBorderColor(Color color);
	void SetBorderSize(int size);
	void Draw();
	static void Input();
};