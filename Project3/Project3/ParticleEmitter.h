#pragma once
#include "particles.h"
#include "maths.h"
#include "cheats.h"
#define PART_SIZE 512

class ParticleEmitter
{
	particle particles[PART_SIZE];

	void emit()
	{
		for (int i = 0; i < PART_SIZE; ++i)
		{
			if (!particles[i].isActive())
			{
				particles[i] = _generate();
				return;
			}
		}
	}
	particle _generate()
	{
		particle part;
		part.pos = pos;
		part.sprite = randomPic();

		part.vel = randDir(angLo, angHi) * lerp(spdLo, spdHi, rand01());

		part.span = lerp(lifespanLo, lifespanHi, rand01());

		part.sCol = lerp(colLoStart, colHiStart, rand01());
		part.eCol = lerp(colLoEnd, colHiEnd, rand01());

		part.sDim = randRange(dimLoStart, dimHiStart);
		part.eDim = randRange(dimLoEnd, dimHiEnd);

		part.time = 0;
		return part;
	}
	float emitTime;
public:
	float emitLow, emitHigh;
	ParticleEmitter() : emitTime(0){}

	vec2 pos;
	unsigned sprite;
	float angLo, angHi;
	float spdLo, spdHi;
	vec2 dimLoStart, dimHiStart;
	vec2 dimLoEnd, dimHiEnd;
	color colLoStart, colHiStart;
	color colLoEnd, colHiEnd;
	float lifespanLo, lifespanHi;

	


	void update(float dt)
	{
		for (int i = 0; i < PART_SIZE; ++i)
			if (particles[i].isActive())
				particles[i].refresh(dt);

		emitTime -= dt;
		while (emitTime < 0)
		{
			emit();
			emitTime += lerp(emitLow, emitHigh, rand01());
		}
	}

};