#include "Box.h"

Box::Box(int x, int y, int width, int height) {
	mX = x;
	mY = y;
	mWidth = width;
	mHWidth = width / 2;
	mHeight = height;
	mHHeight = height / 2;
}

Box::Box() {
	mX = mY = mWidth = mHWidth = mHeight = mHHeight = 0;
}

void Box::setX(int x) {
	mX = x;
}

void Box::setY(int y) {
	mY = y;
}

void Box::setWidth(int wid) {
	mWidth = wid;
	mHWidth = wid / 2;
}

void Box::setHeight(int heig) {
	mHeight = heig;
	mHHeight = heig / 2;
}

int Box::getX() { return mX; }

int Box::getY() { return mY; }

int Box::getLeft() { return mX - mHWidth; }

int Box::getRight() { return mX + mHWidth; }

int Box::getTop() { return mY - mHHeight; }

int Box::getBottom() { return mY + mHHeight; }

int Box::getWidth() { return mWidth; }

int Box::getHeight() { return mHeight; }

bool Box::isContained(int x, int y) {
	{
		if (abs(x - mX) < mHWidth && abs(y - mY) < mHHeight)
		{
			return true;
		}

		return false;
	}
}

bool Box::isContained(SDL_Point p) {
	return isContained(p.x, p.y);
}

bool Box::isCollided(Box b) {
	if (getLeft() > b.getRight() || getRight() < b.getLeft()) { return false; }
	if (getTop() > b.getBottom() || getBottom() < b.getTop()) { return false; }
	return true;
}

bool Box::isCollided(Box a, Box b) {
	return a.isCollided(b);
}