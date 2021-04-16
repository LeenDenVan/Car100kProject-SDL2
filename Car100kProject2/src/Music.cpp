#include "Music.h"

Music::Music() {

}

void Music::play() {
	//Mix_PlayMusic(musicResources[currentMusic], -1);
}

void Music::pause() {
	Mix_PauseMusic();
}

SoundEffect::SoundEffect() {

}

void SoundEffect::play(int SE) {
	Mix_PlayChannel(-1, soundEffects[SE], 1);
}