#include "Scene_Loading.h"
#include "../../Global.h"

Scene_Loading::Scene_Loading(int nextState, bool isShowTitle) {
	fade = SDL_CreateTextureFromSurface(renderer,SDL_CreateRGBSurface(32, SWID, SHEIG, 32, 0, 0, 0, 1));
	SDL_SetTextureBlendMode(fade, SDL_BLENDMODE_BLEND);
	nState = nextState;
	this->isShowTitle = isShowTitle;
}

void Scene_Loading::render() {
	if(isShowTitle)SDL_RenderCopy(renderer, loading, NULL, NULL);
	SDL_Rect shjkdch;
	shjkdch.x = 0;
	shjkdch.y = 0;
	shjkdch.w = 128;
	shjkdch.h = 64;

	SDL_Rect shdest;
	shdest.x = SWID * 0.718;
	shdest.y = SHEIG * 0.75;
	shdest.w = SWID/6;
	shdest.h = SWID/12;
	SDL_RenderCopy(renderer,loadingScene,&shjkdch,&shdest);
	for (int i = 0; i < mp.maples.size(); i++) {
		SDL_Rect tmp;
		tmp.x = mp.maples[i].position.x;
		tmp.y = mp.maples[i].position.y;
		tmp.w = 32*mp.maples[i].size;
		tmp.h = 32*mp.maples[i].size;
		//printf("Maple:%d in (%f,%f)\n", i, mp.maples[i].position.x, mp.maples[i].position.y);
		//printf("maple%d,%d\n", maple.x, maple.y);
		SDL_RenderCopyEx(renderer, loadingScene, &maple, &tmp,mp.maples[i].angle,NULL,SDL_FLIP_NONE);
	}
	if (counter >= 120) {
		SDL_SetTextureAlphaMod(fade, (counter - 120) * 12);
		SDL_RenderCopy(renderer, fade,NULL,NULL);
	}
}

void Scene_Loading::update(){
	if (counter % 2 == 0 && mp.maples.size() < 10) {
		Maple mpTmp;
		mp.maples.push_back(mpTmp);
	}
	mp.MapleUpdate();
	counter++;
	if (counter >= 150) {
		currentState = nState;
		counter = 0;
		nState = 0;
		mp.maples.clear();
	}
}

Maple::Maple() {
	speed = Vector2(0,math.GetRandomDouble(1,8));
	agSpeed = math.GetRandomInt(1, 7);
	position.x = math.GetRandomInt(SWID * 0.718, SWID * 0.9125);
	position.y = SHEIG * 0.75;
	size = math.GetRandomDouble(0.2, 2.0);
}

void Maple::MapleUpdate() {
	for (int i = 0; i < maples.size(); i++) {
		
		maples[i].angle += maples[i].agSpeed;
		maples[i].position = maples[i].position + maples[i].speed;
		if (maples[i].position.y >= 0.75*SHEIG+SWID/12 || maples[i].position.x >= 0.872 * SWID || maples[i].position.x <= 0.715 * SWID) {
			maples.erase(maples.begin() + i);
			i--;
		}
	}
}