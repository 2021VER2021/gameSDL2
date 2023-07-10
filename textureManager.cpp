#include "textureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 255, 255, 255));
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	
	return tex;
}
/* FIX this function, maybe we don't need it */
void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, NULL, NULL, flip);
} 