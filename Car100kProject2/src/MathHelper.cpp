#include "MathHelper.h"
#include <random>
#include <ctime>
#include "Objects/Player.h"

extern Player pl;

MathHelper math;

MathHelper::MathHelper() {
	for (int i = 0; i < 360; i++) {
		mSin[i] = sin(i * PI / 180);
		mCos[i] = cos(i * PI / 180);
	}
}

inline double MathHelper::Fsin(int angle) {
	angle = angle % 360;

	if (angle < 0)
	{
		angle = -angle;
		return -mSin[angle];
	}

	return mSin[angle];
}

inline double MathHelper::Fcos(int angle) {
	angle = angle % 360;

	if (angle < 0)
	{
		angle = -angle;
	}

	return mCos[angle];
}

double MathHelper::Clap(double value, double min, double max) {
	if (value < min)
	{
		return min;
	}
	if (value > max)
	{
		return max;
	}
	return value;
}

double MathHelper::GetRandomDouble(double min, double max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> u(min, max);
	return u(gen);
}

bool MathHelper::GetRandomBool() {
	return GetRandomDouble(0, 1) <= 0.5;
}

int MathHelper::GetRandomInt(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> u(min, max);
	return u(gen);
}

Vector2 MathHelper::GetRandomPosition(double left, double right,double top, double bottom) {
	return Vector2(GetRandomDouble(left, right), GetRandomDouble(top,bottom));
}


Vector2 MathHelper::GetRandomVector(double xmi, double xma, double ymin, double ymax) {
	return GetRandomPosition(xmi, xma, ymin, ymax);
}

Vector2 MathHelper::GetSpeedWithAngle(int angle, double speed) {
	return Vector2(Fcos(angle) * speed, Fsin(angle) * speed);
}

Vector2 MathHelper::GetSpeedWithPosition(Vector2 start, Vector2 end, double speed) {
	Vector2 t = end - start;
	t.Normalize();
	return  t * speed;
}

double MathHelper::GetAngleWithPlayer(Vector2 self) {
	return atan2(self.y - pl.position.y, self.x - pl.position.x)*PI2RAD;
}