#include "Transform.h"
#include "sfwdraw.h"
using namespace sfw;
vec2 Transform::getDirection()
{
	return fromAngle(facing);
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