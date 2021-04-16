#include "Menu.h"
#include "src/Scene/Scene_Loading.h"

extern Scene_Loading loadingS;

TitleMenuItems::TitleMenuItems() {
	fade = SDL_CreateTextureFromSurface(renderer,SDL_CreateRGBSurface(0, SWID, SHEIG, 32, 0, 0, 0, 1));
	SDL_SetTextureBlendMode(fade, SDL_BLENDMODE_BLEND);
}

void TitleMenuItems::eventHandler() {
	if (!chose) {
		int i = 0;
		while (i<eveQue.size()) {
			if (eveQue[i].type == SDL_KEYDOWN && !keyIsPressed) {
				keyIsPressed = true;
				if (eveQue[i].key.keysym.sym == SDLK_UP) {
					if (highlight != 0){
						titleMenuItems[highlight].x -= 5;
						highlight -= 1;
						titleMenuItems[highlight].x += 5;
					}
				}
				else if (eveQue[i].key.keysym.sym == SDLK_DOWN) {
					if (highlight != 7) {
						titleMenuItems[highlight].x -= 5;
						highlight += 1;
						titleMenuItems[highlight].x += 5;
					}
				}
				else if (eveQue[i].key.keysym.sym == SDLK_z) {
					chose = true;

				}
			}
			else if (eveQue[i].type == SDL_KEYUP) {
				keyIsPressed = false;
			}
			i++;
		}
	}
	else {
		flash++;
		if (flash >= 20) {
			switch (highlight) {
			case 0:
			{
				if (flash >= 40) {
					currentState = STATE_Loading;
					loadingS = Scene_Loading(STATE_GameStart,false);
				}

				break;
			}
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			}
		}
	}
}

void TitleMenuItems::render() {
	for (int i = 0; i < 8; i++) {
		if (i != highlight)SDL_RenderCopy(renderer, menuTexts[i][1], NULL, &titleMenuItems[i]);
		else {
			if (chose) {
				if (flash % 2 == 0 && flash <= 40) {
					SDL_RenderCopy(renderer, menuTexts[i][0], NULL, &titleMenuItems[i]);
				}
				else {
					SDL_RenderCopy(renderer, menuTexts[i][1], NULL, &titleMenuItems[i]);
				}
			}
			else {
				SDL_RenderCopy(renderer, menuTexts[i][0], NULL, &titleMenuItems[i]);
			}

		}
	}
	if (flash >= 20) {
		SDL_SetTextureAlphaMod(fade, (flash - 20) * 12);
		SDL_RenderCopy(renderer,fade, NULL, NULL);
	}
}

SceneTitleMenu::SceneTitleMenu() {
		fade = SDL_CreateTextureFromSurface(renderer, SDL_CreateRGBSurface(0, SWID, SHEIG, 32, 0, 0, 0, 1));
		SDL_SetTextureBlendMode(fade, SDL_BLENDMODE_BLEND);
		count = 0;
		tmi = new TitleMenuItems();
}

void SceneTitleMenu::update() {
	tmi->eventHandler();
}

void SceneTitleMenu::render() {
	SDL_RenderCopy(renderer, mainTitleBG, NULL, NULL);
	tmi->render();
	if (count <= 40) {
		SDL_SetTextureAlphaMod(fade, 255 - count * 12);
		SDL_RenderCopy(renderer,fade, NULL,NULL);
		count++;
	}
}