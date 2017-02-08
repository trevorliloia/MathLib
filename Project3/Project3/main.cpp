#include "sfwdraw.h"
#include "maths.h"
#include "particles.h"
#include "ParticleEmitter.h"
#include "cheats.h"
using namespace sfw;
void main()
{
	
	initContext();
	
	loadPics();

	color startColor, endColor;

	startColor.ui_color = MAGENTA;
	endColor.ui_color = CYAN;

	ParticleEmitter pe;
	pe.emitLow = 2.5f;
	pe.emitHigh = 5.f;

	pe.pos = vec2{ 400,300 };
	pe.sprite = randomPic();
	pe.angLo = 0;
	pe.angHi = 360;
	pe.spdLo = 60;
	pe.spdHi = 120;
	pe.dimLoStart = vec2{ 8,8 };
	pe.dimHiStart = vec2{ 32,32 };
	pe.dimLoEnd = vec2{ 256,256 }; 
	pe.dimHiEnd = vec2{ 512,512 };
	pe.colLoStart.ui_color = GREEN;
	pe.colHiStart.ui_color = BLUE;
	pe.colLoEnd.ui_color = YELLOW;
	pe.colHiEnd.ui_color = RED;
	pe.lifespanLo = .9f;
	pe.lifespanHi = 1.5f;


	while (stepContext())
	{
		float dt = getDeltaTime();

		pe.update(dt);
		//drawTexture(sprite[0], 400, 300, 300, 200, 0, true, 0, current.ui_color);
	}

	termContext();
}