#ifndef ENEMY_H_
#define ENEMY_H_

#include "../Vector2.h"

class Enemy{
public:
	Enemy(Vector2 position,int type,int pattern);

	void Render();
	void Update(double elapsedTime);
	void MovementPattern01();



private:
	bool isAlive = true;
	int counter = 0;
	int pattern;
	int hp;
	int item_n[6];
	int type;
	Vector2 position;
	Vector2 acceleration;
	Vector2 speed;
	double angle = 0;
	int bulletTime;
	int bulletType;
};

#endif