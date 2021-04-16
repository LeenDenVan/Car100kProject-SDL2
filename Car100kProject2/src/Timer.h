#ifndef Timer_H_
#define Timer_H_

#include <SDL.h>
#include <ctime>

class Timer {

public:
	Timer();

	void start();
	void stop();
	void pause();
	void resume();

	Uint32 getTicks();

	bool isStarted();
	bool isPaused();

private:

	Uint32 mStartTicks;

	Uint32 mPausedTicks;

	bool mPaused;
	bool mStarted;

};

#endif