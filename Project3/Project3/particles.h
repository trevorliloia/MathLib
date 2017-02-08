#pragma once
#include "sfwdraw.h"
#include "maths.h"
using namespace sfw;
struct particle
{
	unsigned sprite;
	vec2 pos, vel;
	vec2 sDim, eDim;
	color sCol, eCol;

	float time, span;

	particle() : span(-1), time(0) {}

	bool isActive()
	{
		return time < span;
	}

	bool refresh(float dt)
	{
		time += dt;
		float alpha = time / span;
		vec2 dim = lerp(sDim, eDim, alpha);
		color color_A = lerp(sCol, eCol, alpha);

		pos = pos + vel * dt;

		drawTexture(sprite, pos.x, pos.y, dim.x, dim.y, 0, true, 0, color_A.ui_color);
		
		return alpha < 1;
	}
};