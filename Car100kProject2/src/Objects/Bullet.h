#ifndef BULLET_H_
#define BULLET_H_

#include "../Vector2.h"
#include "../Box.h"
#include "../MathHelper.h"
#include <functional>

extern MathHelper math;

extern enum BulletColors {
	BULLET_COLOR_GRAY,
	BULLET_COLOR_SCARLET,
	BULLET_COLOR_RED,
	BULLET_COLOR_PURPLE,
	BULLET_COLOR_PINK,
	BULLET_COLOR_DARK_BLUE,
	BULLET_COLOR_BLUE,
	BULLET_COLOR_SKY_BLUE,
	BULLET_COLOR_CYAN,
	BULLET_COLOR_LIGHT_GREEN,
	BULLET_COLOR_PALE_GREEN,
	BULLET_COLOR_LAWN_GREEN,
	BULLET_COLOR_GREEN_YELLOW,
	BULLET_COLOR_YELLOW,
	BULLET_COLOR_ORENGE,
	BULLET_COLOR_WHITE
};

extern enum BulletTypes {
	BULLET_TYPE_UROKO,
	BULLET_TYPE_RINTAMA,
	BULLET_TYPE_KOTAMA,
	BULLET_TYPE_KOME,
	BULLET_TYPE_CHAIN,
	BULLET_TYPE_HARI,
	BULLET_TYPE_SATSU,
	BULLET_TYPE_JYUU,
	BULLET_TYPE_KANKIN,
	BULLET_TYPE_STAR,
	BULLET_TYPE_TAMA,
	
	//In bullet 2
	BULLET_TYPE_HEART,
	BULLET_TYPE_BAREI,
};

extern enum BulletBareiColors {
	BAREI_RED,
	BAREI_BLUE,
	BAREI_GREEN,
	BAREI_LIGHT_GREEN
};

extern enum BulletHeartColors {
	HEART_GRAY,
	HEART_RED,
	HEART_PURPLE,
	HEART_BLUE,
	HEART_SKY_BLUE,
	HEART_GREEN,
	HEART_YELLOW,
	HEART_WHITE
};

extern enum BulletSize {
	BULLET_SIZE_SMALL,
	BULLET_SIZE_NORMAL,
	BULLET_SIZE_MEDIUM,
	BULLET_SIZE_LARGE,
	BULLET_SIZE_VERT_LARGE
};

class Bullet {
public:
	bool isAlive = true;
	bool isOwn = false;
	int type;
	int color;
	Vector2 position;
	Vector2 speed;
	Vector2 acceleration;
	int counter;
	int angle;
	Box collideBox;
	bool isRedefined = false;
	std::function<bool(int,Bullet*)> bulletEvents;


	Bullet(int type, int color, Vector2 position, Vector2 speed, Vector2 acceleration, int angle, bool isOwn);

	void Render();
	void Update();
	void setEventGroup(std::function<bool(int,Bullet*)> bulletEvent);

private:
	int halfW;
	int halfH;
	int WID;
	int HEI;
};

/*
class PlayerAimedBullet01 : public Bullet{
public:
	PlayerAimedBullet01(int type, int color, Vector2 position, double speed, Vector2 acceleration,int angle):Bullet(type, color, position, math.GetSpeedWithAngle(math.GetAngleWithPlayer(position) + angle, speed), acceleration, angle);
	void Update();
};
*/
#endif