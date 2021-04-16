#include "loadResources.h"
#include <string>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

SDL_Window* window;
SDL_Renderer* renderer;

SDL_GLContext glcont;
TTF_Font *gFont;

SDL_Color SELED;
SDL_Color UNSEL;

SDL_Texture* player;
SDL_Rect playerAnimation[3][8];

SDL_Texture* bullet01;
SDL_Rect bulletSprites01[11][16];

SDL_Texture* mainTitleBG = NULL;
SDL_Rect titleMenuItems[8];

SDL_Texture* menuTexts[8][2];
SDL_Texture* etama2;

SDL_Texture* loadingScene = NULL;
SDL_Rect maple;

SDL_Texture* loading = NULL;

Mix_Chunk *soundEffects[45];

SDL_Rect gamePlaySpace;
SDL_Texture* userInterface;

SDL_Rect jikiMahoujin[2];

int halfXInGamePlaySpace;

SDL_Texture* stage01;
SDL_Texture* bullet02;

//Mix_Music* musicSources[10];
SDL_Rect heartBullets[8];
SDL_Rect bareiBullets[4];

SDL_Texture* loadFromFile(const char* path) {
	SDL_Surface* tempSurf = NULL;
	SDL_Texture* tempTexture = NULL;
	tempSurf = IMG_Load(path);
	if (tempSurf == NULL) {
		printf("Error: Unable to load texture %s. %s", path, SDL_GetError());
		return NULL;
	}
	else {
		tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurf);
		if (tempTexture == NULL) {
			printf("Error:%s", SDL_GetError());
			return NULL;
		}
	}
	SDL_FreeSurface(tempSurf);
	return tempTexture;
}

SDL_Texture* loadFromText(std::string text,SDL_Color color) {
	SDL_Texture* tex = NULL;
	SDL_Surface* temp = TTF_RenderText_Solid(gFont, text.c_str(), color);
	if (temp == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		//Create texture from surface pixels
		tex = SDL_CreateTextureFromSurface(renderer, temp);
		if (tex == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		//Get rid of old surface
		SDL_FreeSurface(temp);
	}

	//Return success
	return tex;
}

void loadResources() {
	player = loadFromFile("res/textures/player/pl00.png");
	bullet01 = loadFromFile("res/textures/bullet/etama.png");

	gFont = TTF_OpenFont("res/font/comic.ttf",28);

	SELED = { 255,0,0 };
	UNSEL = { 220,20,60 };

	menuTexts[0][0] = loadFromText("Game Start    ", SELED);
	menuTexts[0][1] = loadFromText("Game Start    ", UNSEL);
	menuTexts[1][0] = loadFromText("Extra Start   ", SELED);
	menuTexts[1][1] = loadFromText("Extra Start   ", UNSEL);
	menuTexts[2][0] = loadFromText("Practice Start", SELED);
	menuTexts[2][1] = loadFromText("Practice Start", UNSEL);
	menuTexts[3][0] = loadFromText("Replay        ", UNSEL);
	menuTexts[3][1] = loadFromText("Replay        ", UNSEL);
	menuTexts[4][0] = loadFromText("Player Data   ", SELED);
	menuTexts[4][1] = loadFromText("Player Data   ", UNSEL);
	menuTexts[5][0] = loadFromText("Music Room    ", SELED);
	menuTexts[5][1] = loadFromText("Music Room    ", UNSEL);
	menuTexts[6][0] = loadFromText("Option        ", SELED);
	menuTexts[6][1] = loadFromText("Option        ", UNSEL);
	menuTexts[7][0] = loadFromText("Quit          ", UNSEL);
	menuTexts[7][1] = loadFromText("Quit          ", UNSEL);

	for (int i = 0; i < 8; i++) {
		titleMenuItems[i].x = SWID * 3 / 4;
		titleMenuItems[i].y = SHEIG * 0.55 + i * 64;
		titleMenuItems[i].w = SWID / 4;
		titleMenuItems[i].h = SHEIG * 0.1;
	}
	
	mainTitleBG = loadFromFile("res/textures/title/title00a.png");

	bullet02 = loadFromFile("res/textures/bullet/etama8.png");

	soundEffects[STG_SE_GRAZE] = Mix_LoadWAV("res/sounds/se_graze.wav");
	soundEffects[STG_SE_PLDEAD] = Mix_LoadWAV("res/sounds/se_pldead00.wav");
	soundEffects[STG_SE_ALERT] = Mix_LoadWAV("res/sounds/se_alert.wav");
	soundEffects[STG_SE_DAMAGE00] = Mix_LoadWAV("res/sounds/se_damage00.wav");
	soundEffects[STG_SE_DAMAGE01] = Mix_LoadWAV("res/sounds/se_damage01.wav");

	loadingScene = loadFromFile("res/textures/ascii/loading.png");
	maple.x = 0;
	maple.y = 64;
	maple.w = 32;
	maple.h = 32;

	loading = loadFromFile("res/textures/ascii/sig.png");
	userInterface = loadFromFile("res/textures/front/UI.png");
	stage01 = loadFromFile("res/textures/scene/stage01a.png");
	etama2 = loadFromFile("res/textures/bullet/etama2.png");

	jikiMahoujin[0].x = 0;
	jikiMahoujin[0].y = 15;
	jikiMahoujin[0].w = 64;
	jikiMahoujin[0].h = 64;

	jikiMahoujin[1].x = 65;
	jikiMahoujin[1].y = 15;
	jikiMahoujin[1].w = 64;
	jikiMahoujin[1].h = 64;

	gamePlaySpace.x = SWID * 0.046875;
	gamePlaySpace.y = SHEIG * 0.03125;
	gamePlaySpace.w = SWID * 0.6015625;
	gamePlaySpace.h = SHEIG * 0.9375;
	
	halfXInGamePlaySpace = gamePlaySpace.x + gamePlaySpace.w / 2;

	for (int i = 0; i < 8; i++) {
		heartBullets[i].x = i * 32;
		heartBullets[i].y = 0;
		heartBullets[i].w = 32;
		heartBullets[i].h = 32;
	}

	for (int i = 0; i < 4; i++) {
		bareiBullets[i].x = i * 64;
		bareiBullets[i].y = 33;
		bareiBullets[i].w = 32;
		bareiBullets[i].h = 32;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 8; j++) {
			playerAnimation[i][j].x = j * 32;
			playerAnimation[i][j].y = i * 48;
			playerAnimation[i][j].w = 32;
			playerAnimation[i][j].h = 48;
		}
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 16; j++) {
			bulletSprites01[i][j].x = 16 * j;
			bulletSprites01[i][j].y = 16 + 16 * i;
			bulletSprites01[i][j].w = 16;
			bulletSprites01[i][j].h = 16;
		}
	}

}