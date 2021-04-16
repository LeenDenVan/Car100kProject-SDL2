#ifndef Vector2_H_
#define Vector2_H_

#include <cmath>

class Vector2 {
public:
	double x, y;
	Vector2();
	Vector2(double x0, double y0);
	void Normalize();
	void Reserve();
	double Length();
	double Angle();
	double Angle(Vector2);
	Vector2 Rotate(double angle);
	bool operator ==(Vector2& v2);
	bool operator !=(Vector2& v2);
	Vector2 operator +(Vector2& v2);
	Vector2 operator -(Vector2& v2);
	Vector2 operator *(Vector2& v2);
	Vector2 operator *(double s);
	Vector2 operator /(double s);
	Vector2 operator -();
	double Distance(Vector2 v1, Vector2 v2);
	Vector2 Lerp(Vector2 min, Vector2 max, double val);
	double Dot(Vector2 v1, Vector2 v2);

};

#endif
