#include "hdr/Font.h"
#include "hdr/Core.h"

extern Core core;

Font::Font()
{
		
}

void Font::Load(std::string path)
{
	for (int i = 0; i < 256; i++)
		font[i] = TTF_OpenFont(path.c_str(), i);
	std::cout << TTF_GetError() << std::endl;
}

TTF_Font* Font::GetSize(const int x)
{
	if (x < 255)
		return font[x];
	return nullptr;
}
