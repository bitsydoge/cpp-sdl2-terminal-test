#include "hdr/Texture.h"
#include "hdr/Core.h"

extern Core core;

int Texture::RenderCentered(Box* src, Box* dst)
{
	if (!src && dst)
	{
		SDL_Rect s_dst = dst->sdl();
		s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
		return SDL_RenderCopy(core.GetRender(), handle_, NULL, &s_dst);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = src->sdl();
		return SDL_RenderCopy(core.GetRender(), handle_, &s_src, NULL);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopy(core.GetRender(), handle_, NULL, NULL);
	}
	SDL_Rect s_dst = dst->sdl();
	s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
	SDL_Rect s_src = src->sdl();
	return SDL_RenderCopy(core.GetRender(), handle_, &s_src, &s_dst);
}

int Texture::Render(Box* src, Box* dst)
{
	if (!src && dst)
	{
		SDL_Rect s_dst = dst->sdl();
		return SDL_RenderCopy(core.GetRender(), handle_, NULL, &s_dst);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = src->sdl();
		return SDL_RenderCopy(core.GetRender(), handle_, &s_src, NULL);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopy(core.GetRender(), handle_, NULL, NULL);
	}
	SDL_Rect s_dst = dst->sdl();
	SDL_Rect s_src = src->sdl();
	return SDL_RenderCopy(core.GetRender(), handle_, &s_src, &s_dst);
}

void Texture::SetWidth(int w)
{
	w_ = w;
}

void Texture::SetHeight(int h)
{
	h_ = h;
}

int Texture::GetWidth() const
{
	return w_;
}

int Texture::GetHeight() const
{
	return h_;
}

void Texture::CleanHandle() const
{
	SDL_DestroyTexture(handle_);
}

void Texture::SetExistState(bool state)
{
	exist_ = state;
}

bool Texture::Exist() const
{
	return exist_;
}

Texture& Texture::operator=(SDL_Texture* texture)
{
	handle_ = texture;
	return *this;
}
