#ifndef INIT_H_
#define INIT_H_

#include "../Global.h"

enum STG_State {
    STATE_MainMenu,
    STATE_GameStart,
    STATE_SelectPlayer,
    STATE_SelectWingPlane,
    STATE_ExtraStart,
    STATE_PracticeStart,
    STATE_Loading,
    STATE_Replay,
    STATE_PlayerData,
    STATE_Pause,
    STATE_InGaming,
    STATE_MusicRoom,
    STATE_Option,
    STATE_Quit
};

enum MainMenuOptions {
    MOps_GameStart,
    MOps_ExtraStart,
    MOps_PracticeStart,
    MOps_Replay,
    MOps_PlayerData,
    MOps_MusicRoom,
    Mops_Option,
    MOps_Quit
};

bool init();
void close();
bool initGL();

#endif