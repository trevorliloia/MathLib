#pragma once
#include "maths.h"
#include "sfwdraw.h"
#include "ParticleEmitter.h"
#include "particles.h"
using namespace sfw;
#define ARR_SIZE 16
#define ARR_END 99999

unsigned sprite[ARR_SIZE];

//sprite[0]


inline void loadPics()
{
	for (int i = 0; i < ARR_SIZE; ++i)
		sprite[i] = ARR_END;

	sprite[0] = loadTextureMap("../res/1.png");
	sprite[1] = loadTextureMap("../res/2.png");
	sprite[2] = loadTextureMap("../res/3.png");
	sprite[3] = loadTextureMap("../res/4.png");
	sprite[4] = loadTextureMap("../res/5.png");
	sprite[5] = loadTextureMap("../res/6.png");
}

inline unsigned randomPic()
{
	bool picked = false;
	while (!picked)
	{
		int id = rand() % ARR_SIZE;
		if (sprite[id] != ARR_END)
		{
			picked = true;
			return sprite[id];
		}
	}
}

