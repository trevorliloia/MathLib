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

void drawPlane(const Plane & p, unsigned color)
{
	sfw::drawCircle(p.pos.x, p.pos.y, 12, 12, color);
	sfw::drawLine(p.pos.x, p.pos.y, p.pos.x + p.dir.x * 120, p.pos.y + p.dir.y * 120, color);
	sfw::drawLine(p.pos.x, p.pos.y, p.pos.x - p.dir.x * 120, p.pos.y - p.dir.y * 120, color);
}

void drawHull(const Hull & h, unsigned color)
{
	for (int i = 0; i <= h.vsize; ++i)
	{
		if (i = h.vsize)
		{
			sfw::drawLine(h.vertices[i].x, h.vertices[i].y, h.vertices[0].x, h.vertices[0].y, color);
		}
		else
		sfw::drawLine(h.vertices[i].x, h.vertices[i].y, h.vertices[i + 1].x, h.vertices[i + 1].y, color);
	}
}
