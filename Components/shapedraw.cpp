#include "shapedraw.h"
#include "sfwdraw.h"

void drawCircle(const Circle & c, unsigned color)
{
	sfw::drawCircle(c.pos.x, c.pos.y, c.rad, color);
}

void drawAABB(const AABB & a, unsigned color)
{
	sfw::drawLine(a.min().x, a.min().y, a.min().x, a.min().y + (a.he.y * 2), color);
	sfw::drawLine(a.min().x, a.min().y, a.min().x + (a.he.x * 2), a.min().y, color);
	sfw::drawLine(a.max().x, a.max().y, a.max().x, a.max().y - (a.he.y * 2), color);
	sfw::drawLine(a.max().x, a.max().y, a.max().x - (a.he.x * 2), a.max().y, color);
}
