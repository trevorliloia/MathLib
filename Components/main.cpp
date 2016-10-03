#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
using namespace sfw;
void main()
{
	initContext();
	Transform trans;
	Transform stat;
	stat.position = vec2{ 400,300 };
	stat.facing = deg2rad(45);
	stat.scale = vec2{ 24,8 };
	trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 24,8 };
	while (stepContext())
	{
		for (int i = 0; i < 100; ++i)
		{
			
			float x1 = i / 100.f;
			float x2 = (i + 1) / 100.f;
			float y1 = parab(x1);
			float y2 = parab(x2);

			x1 *= 400;
			x2 *= 400;
			y1 *= 400;
			y2 *= 400;

			drawLine(x1, y1, x2, y2);
		}
	}
	termContext();
}