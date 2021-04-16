#ifndef LOADRESOURCES_H_
#define LOADRESOURCES_H_

#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>

const int SHEIG = 720;
const int SWID = 1280;

enum SoundEffectResources {
	STG_SE_GRAZE,
	STG_SE_OPTION,
	STG_SE_PAUSE,
	STG_SE_PLDEAD,
	STG_SE_POWERUP,
	STG_SE_POWER0,
	STG_SE_POWER1,
	STG_SE_SELECT,
	STG_SE_SLASH,
	STG_SE_TIMEOUT,
	STG_SE_ALERT,
	STG_SE_BONUS01,
	STG_SE_BOUNUS01,
	STG_SE_CANCEL,
	STG_SE_DAMAGE00,
	STG_SE_DAMAGE01,
	STG_SE_HINT,
};

enum MusicResources {
	STG_MUS_MainTheme,
	STG_MUS_SC01,
	STG_MUS_SC01BOSS,
};

SDL_Texture* loadFromFile(const char* path);

void loadResources();

#endif