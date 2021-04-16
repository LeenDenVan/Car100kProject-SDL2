#ifndef BOX_H_
#define BOX_H_

#include <SDL.h>

class Box {

public:
	Box(int x, int y, int width, int height);
	Box();

	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	int getWidth();
	void setWidth(int wid);
	int getHeight();
	void setHeight(int heig);
	int getLeft();
	int getRight();
	int getTop();
	int getBottom();
	bool isContained(int x, int y);
	bool isContained(SDL_Point p);
	bool isCollided(Box b);
	bool isCollided(Box b1, Box b2);


	private:
		int mX;
		int mY;
		int mWidth;
		int mHeight;
		int mHWidth;
		int mHHeight;
};

#endif