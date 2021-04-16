#define _CRT_SECURE_NO_WARNINGS

#include "Global.h"
#include "src/Objects/WingPlane.h"
#include "src/Scene/Background.h"
#include "src/Scene/UI.h"

extern int currentState = STATE_Loading;

bool loadMedia();

SDL_GLContext gCont;

BulletManager bm;

Player pl(0);
WingPlane wp(0);

Scene_Loading loadingS(STATE_MainMenu,true);

Background bg;
UI userInt;

std::vector<SDL_Event> eveQue;

bool loadMedia() {
    bool success = true;
    loadResources();
    return success;
}

int main(int argc, char* args[])
{
    if (!init()) {
    }
    else {
        if (!loadMedia()) {
            printf("Unable to load Media\n");
        }
        else {

            SceneTitleMenu stm;

            bool quit = false;

            SDL_Event e;

            int p = 1;
            WingPlane wp(0);
            pl.setWingPlane(&wp);

            int scrollingOffset = 0;

            while (!quit) {

                while (SDL_PollEvent(&e) != 0) {

                    const Uint8* statea = SDL_GetKeyboardState(NULL);

                    if (e.type == SDL_QUIT || statea[SDL_SCANCODE_ESCAPE]) {
                        printf("Here\n");
                        quit = true;
                    }
                    eveQue.push_back(e);
                }

                const Uint8* statea = SDL_GetKeyboardState(NULL);

                SDL_PumpEvents();

                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
                SDL_RenderClear(renderer);
                switch (currentState) {
                case STATE_MainMenu:
                    stm.render();   
                    stm.update();
                    break;
                case STATE_GameStart:
                {   //callFunctionWithNoArg(pModule, "printHello");
                    bg.render();
                    bg.update();
                    //bm.shot01SilentSenena();
                    bm.shot03();
                    //bm.HorizonOfWaveAndParticles();
                    bm.renderBullets();
                    bm.updateBullets(0.02);

                    pl.Render();
                    pl.Update(0.08);
                    userInt.render();
                    break;
                }
                case STATE_ExtraStart:
                    break;
                case STATE_InGaming:
                    break;
                case STATE_Pause:
                    break;
                case STATE_Loading:
                    loadingS.render();
                    loadingS.update();
                    break;
                case STATE_PracticeStart:
                    break;
                case STATE_SelectPlayer:
                    break;
                case STATE_SelectWingPlane:
                    break;
                case STATE_PlayerData:
                    break;
                case STATE_Quit:
                    goto game_end;
                    break;
                }

                SDL_RenderPresent(renderer);
                eveQue.clear();
            }
        }
    }
    game_end:
    close();

    return 0;
}