#ifndef MUSIC_H_
#define MUSIC_H_

#include "../Global.h"

class Music {
public:
	Music();
	void play();
	void pause();
	void setCurrentMusic(int nMusic);

private:
	int currentMusic;
};

class SoundEffect {
public:
	SoundEffect();
	void play(int nSE);
private:
};

#endif
