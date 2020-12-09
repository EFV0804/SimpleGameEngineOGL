#pragma once
#include "Window.h"
#include "RendererSDL.h"
#include "Vector2.h"
#include "Timer.h"
#include "Actor.h"
#include <vector>
#include "Assets.h"
#include"SpriteComponent.h"
using std::vector;

class Game
{
public:
	static Game& instance()
	{
		static Game inst;
		return inst;
	}
	Game(const Game&) = delete; //deleting copy constructor
	Game& operator = (const Game&) = delete; //deleting assignment operator
	Game(Game&&) = delete;
	Game& operator = (Game&&) = delete;
	RendererSDL& getRenderer() { return renderer; }
	IRenderer::Type type() { return IRenderer::Type::SDL; }

private:
	Game() : isRunning(true),
		isUpdatingActors(false)
	{}

public:
	bool initialize();
	void load();
	void loop();
	void unload();
	void close();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);

private:
	void processInput();
	void update(float dt);
	void render();

	Window window;
	bool isRunning;
	RendererSDL renderer;

	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;
};