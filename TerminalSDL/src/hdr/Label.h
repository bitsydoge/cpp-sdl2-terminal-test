#pragma once
#include "Texture.h"
#include "Color.h"
#include "hdr/Core.h"

class Label
{
	int posx_, posy_;
	std::string TextActual_;
	std::string TextLast_;
	Color ColorActual_;
	Color ColorLast_;
	int SizeActual_;
	int SizeLast_;
	bool HaveTexture_;
	Texture cache_;

public:
	Label();
	void UpdateTexture();
	void Draw();
	void SetPos(int x, int y);
	void SetPosX(int x);
	void SetPosY(int y);
	void SetColor(Color color);
	void SetSize(int size);
	void SetText(std::string text);
	int GetWidth() const;
	int GetHeight() const;

	Label& operator=(const Color& color);
	Label& operator=(const std::string& text);
	Label& operator=(const int& size);
	Label& operator=(const Box& box);


};

