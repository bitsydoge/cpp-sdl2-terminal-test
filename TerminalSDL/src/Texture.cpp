#include "hdr/Texture.h"
#include "hdr/Core.h"

extern Core core;

int TextureRenderCentered(Texture *texture, Box* src, Box* dst)
{
	if (!src && dst)
	{
		SDL_Rect s_dst = dst->sdl();
		s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
		return SDL_RenderCopy(core.GetRender(), texture->handle, NULL, &s_dst);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = src->sdl();
		return SDL_RenderCopy(core.GetRender(), texture->handle, &s_src, NULL);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopy(core.GetRender(), texture->handle, NULL, NULL);
	}
	SDL_Rect s_dst = dst->sdl();
	s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
	SDL_Rect s_src = src->sdl();
	return SDL_RenderCopy(core.GetRender(), texture->handle, &s_src, &s_dst);
}

int TextureRender(Texture *texture, Box* src, Box* dst)
{
	if (!src && dst)
	{
		SDL_Rect s_dst = dst->sdl();
		return SDL_RenderCopy(core.GetRender(), texture->handle, NULL, &s_dst);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = src->sdl();
		return SDL_RenderCopy(core.GetRender(), texture->handle, &s_src, NULL);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopy(core.GetRender(), texture->handle, NULL, NULL);
	}
	SDL_Rect s_dst = dst->sdl();
	SDL_Rect s_src = src->sdl();
	return SDL_RenderCopy(core.GetRender(), texture->handle, &s_src, &s_dst);
}