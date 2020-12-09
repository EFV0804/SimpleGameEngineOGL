#pragma once
#include "Rectangle.h"
#include <SDL.h>
#include "Window.h"
#include"Vector2.h"
#include"Actor.h"
#include"IRenderer.h"

class RendererSDL: public IRenderer
{
public:
	enum class Flip
	{
		None = SDL_FLIP_NONE,
		Horizontal = SDL_FLIP_HORIZONTAL,
		Vertical = SDL_FLIP_VERTICAL
	};

	RendererSDL();
	RendererSDL(const RendererSDL&) = delete;
	RendererSDL& operator = (const RendererSDL&) = delete;

	bool initialize(Window& window);

	void beginDraw();
	void draw();
	void endDraw();

	IRenderer::Type type() { return Type::SDL; }

	void drawRect(const Rectangle& rect) const;
	void addSprite(class SpriteComponent* sprite);
	void removeSprite(class SpriteComponent* sprite);
	void drawSprites();
	void drawSprite(const class Actor&, const class Texture& tex, struct Rectangle srcRect, Vector2 origin, Flip flip) const override;

	void close();
	inline SDL_Renderer* toSDLRenderer() const { return SDLRenderer; }
private:
	SDL_Renderer* SDLRenderer = nullptr;
	std::vector<SpriteComponent*>sprites;
};

