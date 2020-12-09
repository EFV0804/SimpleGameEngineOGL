#pragma once
#include<string>
#include "RendererSDL.h"
using std::string;

class Texture
{
public:
	Texture();
	~Texture();

	void unload();
	bool load(RendererSDL& renderer, const string& filenameP);
	inline SDL_Texture* toSDLTexture() const { return SDLTexture; }
	void updateInfo(int& widthOut, int& heightOut);

	inline int getWidth() const { return width; }
	inline int getHeight() const { return height; }


private:
	string filename;
	SDL_Texture* SDLTexture;
	int width;
	int height;
};