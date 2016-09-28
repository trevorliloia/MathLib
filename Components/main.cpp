#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
using namespace sfw;
void main()
{
	initContext();
	Transform trans;
	trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 24,8 };
	while (stepContext())
	{
		trans.facing += getDeltaTime();
		trans.debugDraw();
	}
	termContext();
}