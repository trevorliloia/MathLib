#pragma once
#include "vec2.h"
class Transform
{	


public:
	Transform();
	Transform(float x, float y, float w, float h, float a);

	vec2 position;
	vec2 scale;
	float facing;
	vec2 getDirection();
	void setDirection(const vec2 &dir);
	void debugDraw();
};