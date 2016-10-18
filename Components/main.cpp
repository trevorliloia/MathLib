#include "sfwdraw.h"
#include "vec2.h"
#include "Transform.h"
#include "flops.h"
#include "Rigidbody.h"
#include "SpaceshipLocomotion.h"
#include "SpaceshipController.h"
using namespace sfw;
void main()
{
	initContext();
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

			if (playerTransform.m_position.x > 800) playerTransform.m_position.x = 1;
			if (playerTransform.m_position.y > 600) playerTransform.m_position.y = 1;

			if (playerTransform.m_position.x < 0) playerTransform.m_position.x = 799;
			if (playerTransform.m_position.y < 0) playerTransform.m_position.y = 599;
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
			if (getKey('U'))
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
			ST3.m_facing /= 1.3;
			
			playerRigidBody.debugDraw(playerTransform);
	
			drawCircle(playerTransform.m_position.x, playerTransform.m_position.y, 10.f);
			angleAdjust = -(normal(frameLast - framePos) * 10);
			drawLine(playerTransform.m_position.x, playerTransform.m_position.y, playerTransform.m_position.x + playerTransform.getUp().x * 50, playerTransform.m_position.y + playerTransform.getUp().y * 50);


			playerTransform.debugDraw();
			ST1.debugDraw();
			ST2.debugDraw();
			ST3.debugDraw();
			ST4.debugDraw();
	}
	sfw::termContext();
}