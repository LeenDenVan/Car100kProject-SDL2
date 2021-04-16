#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <GL/glew.h>
#include <GL/GLU.h>
#include <SDL_opengl.h>
#include <cstdio>
#include <string>
#include <cstdio>

#include <Python.h>
#include "src/define.h"
#include "src/init.h"
#include "src/MathHelper.h"
#include "src/Objects/Player.h"
#include "src/Managers/BulletManager.h"
#include "Menu.h"
#include "src/Scene/Scene_Loading.h"

const int SHEIG = 960;
const int SWID = 1280;

extern MathHelper math;

extern PyObject* pModule;

extern SDL_Renderer* renderer;
extern SDL_Window* window;

extern SDL_Texture* player;
extern SDL_Rect playerAnimation[3][8];
extern TTF_Font gFont;

extern SDL_Texture* menuTexts[8][2];

extern Mix_Chunk* soundEffects[45];
extern Mix_Music* bgms[10];

extern SDL_Texture* bullet01;
extern SDL_Texture* bullet02;

extern SDL_Rect heartBullets[8];
extern SDL_Rect bareiBullets[4];

extern SDL_Rect bulletSprites01[11][16];

extern void loadResources();
extern Player pl;

extern SDL_Texture* etama2;
extern SDL_Rect jikiMahoujin[2];

extern SDL_Texture* mainTitleBG;

extern SDL_Rect titleMenuItems[8];
extern SDL_Texture* menuTexts[8][2];

extern SDL_Texture* loadingScene;
extern SDL_Rect maple;
extern SDL_Texture* loading;

extern SDL_GLContext glcont;

extern int currentState;

extern enum STG_State;
extern enum SoundEffectResources;
extern enum MusicResources;
extern enum MainMenuOptions;

extern std::vector<SDL_Event> eveQue;

extern SDL_Rect gamePlaySpace;
extern SDL_Texture* userInterface;

extern SDL_Texture* stage01;
extern Mix_Music* musicResources[10];

extern int halfXInGamePlaySpace;



#endif