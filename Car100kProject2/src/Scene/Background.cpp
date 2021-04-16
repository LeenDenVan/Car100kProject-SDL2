#include "Background.h"
#include "../../Global.h"

Background::Background() {

}

void Background::render() {
	SDL_Rect dest = { gamePlaySpace.x, scrollingOffset+gamePlaySpace.h,gamePlaySpace.w/2,gamePlaySpace.h };
	SDL_Rect dest3 = { gamePlaySpace.x, scrollingOffset,gamePlaySpace.w/2,gamePlaySpace.h };
	SDL_Rect dest2 = { gamePlaySpace.x,scrollingOffset - gamePlaySpace.h,gamePlaySpace.w/2,gamePlaySpace.h };
	SDL_Rect dest4 = { halfXInGamePlaySpace, scrollingOffset + gamePlaySpace.h,gamePlaySpace.w / 2,gamePlaySpace.h };
	SDL_Rect dest6 = { halfXInGamePlaySpace, scrollingOffset,gamePlaySpace.w / 2,gamePlaySpace.h };
	SDL_Rect dest5 = { halfXInGamePlaySpace,scrollingOffset - gamePlaySpace.h,gamePlaySpace.w / 2,gamePlaySpace.h };
	SDL_RenderCopy(renderer, stage01, NULL, &dest);
	SDL_RenderCopy(renderer, stage01, NULL, &dest3);
	SDL_RenderCopy(renderer, stage01, NULL, &dest2);
	SDL_RenderCopyEx(renderer, stage01, NULL, &dest4, 0, NULL, SDL_FLIP_HORIZONTAL); 
	SDL_RenderCopyEx(renderer, stage01, NULL, &dest6, 0, NULL, SDL_FLIP_HORIZONTAL);
	SDL_RenderCopyEx(renderer, stage01, NULL, &dest5, 0, NULL, SDL_FLIP_HORIZONTAL);
}

void Background::update() {
	scrollingOffset += 4;
	if (scrollingOffset > gamePlaySpace.h)scrollingOffset = 0;
}