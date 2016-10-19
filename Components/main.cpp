#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
#include "PlanetaryMotor.h"
using namespace sfw;

void main()
{	
	float W = 1920, H = 1080;
	initContext(W,H);
	Transform trans;
	Transform stat;
	stat.m_position = vec2{ 400,300 };
	stat.m_facing = deg2rad(45);
	stat.m_scale = vec2{ 24,8 };
	trans.m_position = vec2{ 400,300 };
	trans.m_facing = deg2rad(45);
	trans.m_scale = vec2{ 24,8 };

	vec2 player = { 400,400 };
	vec2 playerVel = { 0,0 };
	vec2 framePos = player;
	vec2 frameLast = playerVel;
	vec2 angleAdjust = (normal(frameLast - framePos) * 10);

	Transform playerTransform(200, 200, 1, 1, 0);
	Rigidbody playerRigidBody;
	playerRigidBody.velocity = vec2{ 0,0 };
	SpaceshipLocomotion PlayerLoco;
	SpaceshipController playerCtrl;

	Transform ST1(0, -50);
	Transform ST2(0, -50);
	Transform ST3(0, -50);
	Transform ST4(0, -50);

	ST1.m_parent = &playerTransform;
	ST2.m_parent = &ST1;
	ST3.m_parent = &ST2;
	ST4.m_parent = &ST3;

	Transform sun(960, 540, 1, 1, 0);
	sun.size = 12;
	Rigidbody sunRB;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationspeed = 1;
	sunMotor.m_maxspeed = 1;
	Transform earth(0, -30);
	earth.size = 5;
	earth.m_parent = &sun;

	Transform mercMotor(960, 540, 1, 1, 0);
	Rigidbody mercRB;
	PlanetaryMotor mercuryMotor;
	mercuryMotor.m_rotationspeed = 1.607;
	mercuryMotor.m_maxspeed = 1.607;
	Transform mercury(0, -9);
	mercury.size = 1;
	mercury.m_parent = &mercMotor;

	Transform venMotor(960, 540, 1, 1, 0);
	Rigidbody venRB;
	PlanetaryMotor venusMotor;
	venusMotor.m_rotationspeed = 1.174;
	venusMotor.m_maxspeed = 1.174;
	Transform venus(0, -21);
	venus.size = 3;
	venus.m_parent = &venMotor;

	Transform marMotor(960, 540, 1, 1, 0);
	Rigidbody marRB;
	PlanetaryMotor marsMotor;
	marsMotor.m_rotationspeed = .802;
	marsMotor.m_maxspeed = .802;
	Transform mars(0, -45);
	mars.size = 4;
	mars.m_parent = &marMotor;

	Transform jupMotor(960, 540, 1, 1, 0);
	Rigidbody jupRB;
	PlanetaryMotor jupiterMotor;
	jupiterMotor.m_rotationspeed = .434;
	jupiterMotor.m_maxspeed = .434;
	Transform jupiter(0, -156);
	jupiter.size = 20;
	jupiter.m_parent = &jupMotor;

	Transform satMotor(960, 540, 1, 1, 0);
	Rigidbody satRB;
	PlanetaryMotor saturnMotor;
	saturnMotor.m_rotationspeed = .323;
	saturnMotor.m_maxspeed = .323;
	Transform saturn(0, -285);
	saturn.size = 15;
	saturn.m_parent = &satMotor;

	Transform uraMotor(960, 540, 1, 1, 0);
	Rigidbody uraRB;
	PlanetaryMotor uranusMotor;
	uranusMotor.m_rotationspeed = .228;
	uranusMotor.m_maxspeed = .228;
	Transform uranus(0, -423);
	uranus.size = 12;
	uranus.m_parent = &uraMotor;

	Transform nepMotor(960, 540, 1, 1, 0);
	Rigidbody nepRB;
	PlanetaryMotor neptuneMotor;
	neptuneMotor.m_rotationspeed = .182;
	neptuneMotor.m_maxspeed = .182;
	Transform neptune(0, -900);
	neptune.size = 13;
	neptune.m_parent = &nepMotor;

	Transform pluMotor(960, 540, 1, 1, 0);
	Rigidbody pluRB;
	PlanetaryMotor plutoMotor;
	plutoMotor.m_rotationspeed = .159;
	plutoMotor.m_maxspeed = .159;
	Transform pluto(0, -1185);
	pluto.size = 1;
	pluto.m_parent = &pluMotor;

	while (stepContext())
	{
		float delta = getDeltaTime();
		frameLast = player;
		//for (int i = 0; i < 100; ++i)
		//{
		/*if (getKey('W')) playerRigidBody.velocity.y += 3.0f;
		if (getKey('A')) playerRigidBody.velocity.x -= 3.0f;
		if (getKey('S')) playerRigidBody.velocity.y -= 3.0f;
		if (getKey('D')) playerRigidBody.velocity.x += 3.0f;

		if (getKey('Q')) playerRigidBody.angularVelocity -= 1.0f;
		if (getKey('E')) playerRigidBody.angularVelocity += 1.0f;*/
		
			
			PlayerLoco.update(playerTransform, playerRigidBody);
			playerCtrl.update(PlayerLoco);
			playerRigidBody.integrate(playerTransform, delta);
			playerTransform.m_position += playerRigidBody.velocity;
			framePos = playerTransform.m_position;
			playerRigidBody.velocity.x /= 1.2f;
			playerRigidBody.velocity.y /= 1.2f;
			playerRigidBody.angularVelocity /= 1.1f;

			if (playerTransform.m_position.x > 1920) playerTransform.m_position.x = 1;
			if (playerTransform.m_position.y > 1080) playerTransform.m_position.y = 1;

			if (playerTransform.m_position.x < 0) playerTransform.m_position.x = 1919;
			if (playerTransform.m_position.y < 0) playerTransform.m_position.y = 1079;
			/*float x1 = i / 100.f;
			float x2 = (i + 1) / 100.f;
			float y1 = parab(x1);
			float y2 = parab(x2);

			x1 *= 400;
			x2 *= 400;
			y1 *= 400;
			y2 *= 400;

			drawLine(x1, y1, x2, y2);*/
		//}
			/*if (getKey('U'))
			{
				ST1.m_facing += 0.13;
			}
			if (getKey('J'))
			{
				ST1.m_facing -= 0.13;
			}

			if (getKey('I'))
			{
				ST2.m_facing += 0.13;
			}
			if (getKey('K'))
			{
				ST2.m_facing -= 0.13;
			}

			if (getKey('O'))
			{
				ST3.m_facing += 0.13;
			}
			if (getKey('L'))
			{
				ST3.m_facing -= 0.13;
			}

			if (getKey('A'))
			{
				ST1.m_facing -= 0.13;
				ST2.m_facing -= 0.13;
				ST3.m_facing -= 0.13;
			}

			if (getKey('D'))
			{
				ST1.m_facing += 0.13;
				ST2.m_facing += 0.13;
				ST3.m_facing += 0.13;
			}

			ST1.m_facing /= 1.3;
			ST2.m_facing /= 1.3;
			ST3.m_facing /= 1.3;*/
			
			sunRB.integrate(sun, getDeltaTime());
			sunMotor.update(sunRB);
			sun.debugDraw();
			earth.debugDraw();

			mercRB.integrate(mercMotor, getDeltaTime());
			mercuryMotor.update(mercRB);
			mercury.debugDraw();

			venRB.integrate(venMotor, getDeltaTime());
			venusMotor.update(venRB);
			venus.debugDraw();

			marRB.integrate(marMotor, getDeltaTime());
			marsMotor.update(marRB);
			mars.debugDraw();

			jupRB.integrate(jupMotor, getDeltaTime());
			jupiterMotor.update(jupRB);
			jupiter.debugDraw();

			satRB.integrate(satMotor, getDeltaTime());
			saturnMotor.update(satRB);
			saturn.debugDraw();

			uraRB.integrate(uraMotor, getDeltaTime());
			uranusMotor.update(uraRB);
			uranus.debugDraw();

			nepRB.integrate(nepMotor, getDeltaTime());
			neptuneMotor.update(nepRB);
			neptune.debugDraw();

			pluRB.integrate(pluMotor, getDeltaTime());
			plutoMotor.update(pluRB);
			pluto.debugDraw();

			playerRigidBody.debugDraw(playerTransform);
	
			drawCircle(playerTransform.m_position.x, playerTransform.m_position.y, 10.f);
			angleAdjust = -(normal(frameLast - framePos) * 10);
			drawLine(playerTransform.m_position.x, playerTransform.m_position.y, playerTransform.m_position.x + playerTransform.getUp().x * 50, playerTransform.m_position.y + playerTransform.getUp().y * 50);


			playerTransform.debugDraw();
			/*ST1.debugDraw();
			ST2.debugDraw();
			ST3.debugDraw();
			ST4.debugDraw();*/
	}
	sfw::termContext();
}