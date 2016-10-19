#include "Transform.h"
#include "sfwdraw.h"
#include "mat3.h"
using namespace sfw;

//Transform::Transform()
//{
//	m_position = vec2{ 0,0 };
//	m_scale	 = vec2{ 1,1 };
//	m_facing = 1.0f;
//}

Transform::Transform(float x, float y, float w, float h, float a)
{
	m_position.x = x;
	m_position.y = y;

	m_scale.x = w;
	m_scale.y = h;

	m_facing = a;
	
	m_parent = nullptr;
}

vec2 Transform::getDirection()
{
	return fromAngle(m_facing);
}
vec2 Transform::getUp()
{
	return -perp(getDirection());
}
void Transform::setDirection(const vec2 &dir)
{
	m_facing = angle(dir);
}



mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
	{
		return getLocalTransform();
	}
	else
	return m_parent->getGlobalTransform() * getLocalTransform();
}

mat3 Transform::getLocalTransform() const
{
	mat3 S = scale(m_scale.x, m_scale.y);
	mat3 T = translate(m_position.x, m_position.y);
	mat3 R = rotate(m_facing);
	return (T * R * S);
}

void Transform::debugDraw(const mat3 &T) const
{	
	mat3 L   = T * getGlobalTransform();
	vec3 pos = L[2];

	vec3 sgp = m_parent ? m_parent->getGlobalTransform()[2] : pos;

	vec3 right = L * vec3{ 10,0,1 };
	vec3 up    = L * vec3{ 0,10,1 };
	
	drawLine(pos.x, pos.y, right.x, right.y, RED);
	drawLine(pos.x, pos.y, up.x, up.y, GREEN);
	drawLine(sgp.x, sgp.y, pos.x, pos.y, BLUE);

	sfw::drawCircle(pos.x, pos.y, size, 12, GREEN);
	/*drawCircle(position.x, position.y, 12);
	vec2 dirEnd = position + getDirection() * 12;
	vec2 upEnd = position - perp(getDirection()) * 12;
	drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);*/
	//drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);
}