#pragma once
#ifndef _POINT_H__
#define _POINT_H__


class Point
{
public:
	Point(float x = 0, float y = 0) :x(x), y(y) {}
	float getX() const { return x; }
	float getY() const { return y; }
private:
	float x, y;
};

#endif