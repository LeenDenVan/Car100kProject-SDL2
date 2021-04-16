#ifndef SCENE_LOADING_H_
#define SCENE_LOADING_H_

#include "../Vector2.h"
#include <SDL_image.h>
#include <vector>

class Maple {
public:
	Vector2 speed;
	Vector2 position;
	int angle = 1;
	int agSpeed;
	int size;
	std::vector<Maple> maples;
	Maple();
	void MapleUpdate();
};

class Scene_Loading {
public:
	Maple mp;
	SDL_Texture* fade;
	int counter = 0;
	int nState;
	bool isShowTitle;
	
	Scene_Loading(int nextState, bool isShowTitle);
	void render();
	void update();
}; 

#endif