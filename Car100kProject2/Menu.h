#ifndef MENU_H_
#define MENU_H_
#include "Global.h"

class TitleMenuItems {
public:
	bool keyIsPressed = false;
	int highlight = 0;
	bool chose = false;
	int flash = 0;

	SDL_Texture* fade;

	TitleMenuItems();

	void eventHandler();

	void render();
};

class SceneTitleMenu {
public:
	SDL_Texture* fade;
	int count;
	TitleMenuItems* tmi;
	SceneTitleMenu();

	void update();

	void render();
};

#endif