#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Vector2.h"
#include "../Box.h"
class WingPlane;

class Player{
public:
	Vector2 position;
	Box CollideBox;
	Vector2 speed;
	Vector2 acceleration;
	Player(int id);
	void Render();
	void Update(double elapsedTime);
	void setWingPlane(WingPlane* wp);
	void decLife();

private:
	bool isAlive = true;
	bool isShoot = false;
	bool isHit = false;
	int life;
	bool isSlowMode = false;
	bool isGodTime = false;
	int power = 0;
	int graze = 0;
	int animationFrame = 0;
	WingPlane* wingplane;
	int counter = 0;
	double godTime = 0;
	int score = 0;
	int state = 0;
	int width;
	int height;
	int id;
};

#endif