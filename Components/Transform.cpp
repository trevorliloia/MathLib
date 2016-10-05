#include "Transform.h"
#include "sfwdraw.h"
using namespace sfw;

Transform::Transform()
{
	position = vec2{ 0,0 };
	scale	 = vec2{ 1,1 };
	facing = 1.0f;
}

Transform::Transform(float x, float y, float w, float h, float a)
{
	position.x = x;
	position.y = y;

	scale.x = w;
	scale.y = h;

	facing = a;
}

vec2 Transform::getDirection()
{
	return fromAngle(facing);
}
vec2 Transform::getUp()
{
	return -perp(getDirection());
}
void Transform::setDirection(const vec2 &dir)
{
	facing = angle(dir);
}
void Transform::debugDraw()
{
	drawCircle(position.x, position.y, 12);
	vec2 dirEnd = position + getDirection() * 12;
	vec2 upEnd = position - perp(getDirection()) * 12;
	drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);
	//drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);
}