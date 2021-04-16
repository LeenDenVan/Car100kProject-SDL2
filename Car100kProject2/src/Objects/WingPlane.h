#ifndef WINGPLANE_H_
#define WINGPLANE_H_

#include "../Vector2.h"
#include "../../Global.h"

class WingPlane {
public:
	Vector2 position[15];
	double angleSpeed = 0;
	int currentCount=0;
	int maxCount;
	double angle=0;
	double delayShootTime = 0;
	double delayTime = 0;
	bool isShoot = false;
	BulletManager bm;

	WingPlane(int type);
	WingPlane(){}
	void Update(double elapsedTime);
	void Render();
	void Shoot();

private:

};

#endif