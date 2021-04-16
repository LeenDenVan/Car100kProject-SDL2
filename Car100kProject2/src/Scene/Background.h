#ifndef BACKGROUND_H_
#define BACKGROUND_H_

class Background {
public:
	int scrollingOffset = 0;
	Background();
	void render();
	void update();
private:
};

#endif