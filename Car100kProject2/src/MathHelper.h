#ifndef MATHHELPER_H_
#define MATHHELPER_H_

#include "Vector2.h"
#include "define.h"
#include <cmath>

class Player;

class MathHelper {
public:
	MathHelper();
	inline double Fsin(int angle);
	inline double Fcos(int angle);
	double Clap(double value, double min, double max);
	double GetRandomDouble(double min, double max);
	bool GetRandomBool();
	int GetRandomInt(int min, int max);
	double GetAngleWithPlayer(Vector2 self);
	Vector2 GetRandomPosition(double left, double right, double top, double bottom);
	Vector2 GetRandomVector(double xmi, double xma, double ymin, double ymax);
	Vector2 GetSpeedWithAngle(int angle, double speed);
	Vector2 GetSpeedWithPosition(Vector2 start, Vector2 end, double speed);

private:
	double mSin[360];
	double mCos[360];
};

#endif