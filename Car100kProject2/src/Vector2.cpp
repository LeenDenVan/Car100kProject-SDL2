#include "Vector2.h"

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(double x0, double y0) {
	x = x0;
	y = y0;
}

void Vector2::Normalize() {
    double m = x * x + y * y;

    if (m < 0.00001f)
    {
        m = 1;
    }

    m = 1.0 / sqrt(m);

    x *= m;
    y *= m;
}

void Vector2::Reserve() {
    x = -x;
    y = -y;
}

double Vector2::Length() {
    return sqrt(x * x + y * y);
}

double Vector2::Angle() {
    return atan2(y, x);
}

double Vector2::Angle(Vector2 v) {
    Vector2 t = *this;
    t.Normalize();
    v.Normalize();
    return acos(Dot(t, v));
}

Vector2 Vector2::Rotate(double angle)
{
    double a = x;
    double b = y;

    a = x *cos(angle) - y * sin(angle);
    b = y * sin(angle) + y * cos(angle);

    return Vector2(a, b);
}

bool Vector2::operator ==(Vector2& v2) {
    if (x == v2.x) {
        return y == v2.y;
    }
    return false;
}

bool Vector2::operator !=(Vector2& v2) {
    if (x != v2.x || y != v2.y) {
        return true;
    }
}

Vector2 Vector2::operator +(Vector2& v2) {
    Vector2 t;
    t.x = x + v2.x;
    t.y = y + v2.y;
    return t;
}

Vector2 Vector2::operator -(Vector2& v2) {
    Vector2 t;
    t.x = x - v2.x;
    t.y = y - v2.y;
    return t;
}

Vector2 Vector2::operator *(Vector2& v2) {
    return Vector2(x * v2.x, y * v2.y);
}

Vector2 Vector2::operator *(double s) {
    return Vector2(s * x, s * y);
}

Vector2 Vector2::operator /(double s) {
    return Vector2(x / s, y / s);
}

Vector2 Vector2::operator -() {
    return Vector2(-x, -y);
}

double Vector2::Distance(Vector2 v1, Vector2 v2) {
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}

Vector2 Vector2::Lerp(Vector2 min, Vector2 max, double val) {
    return Vector2(min.x + (max.x - min.x) * val, min.y + (max.y - min.y) * val);
}

double Vector2::Dot(Vector2 v1, Vector2 v2) {
    return v1.x * v2.x + v1.y * v2.y;
}