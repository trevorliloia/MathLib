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
	stat.position = vec2{ 400,300 };
	stat.facing = deg2rad(45);
	stat.scale = vec2{ 24,8 };
	trans.position = vec2{ 400,300 };
	trans.facing = deg2rad(45);
	trans.scale = vec2{ 24,8 };

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

			
			PlayerLoco.update(playerRigidBody, getDeltaTime());
			playerCtrl.update(PlayerLoco);
			playerRigidBody.integrate(playerTransform, delta);
			playerTransform.position += playerRigidBody.velocity;
			framePos = playerTransform.position;
			playerRigidBody.velocity.x /= 1.2f;
			playerRigidBody.velocity.y /= 1.2f;


			if (playerTransform.position.x > 800) playerTransform.position.x = 1;
			if (playerTransform.position.y > 600) playerTransform.position.y = 1;

			if (playerTransform.position.x < 0) playerTransform.position.x = 799;
			if (playerTransform.position.y < 0) playerTransform.position.y = 599;
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
			

			drawCircle(playerTransform.position.x, playerTransform.position.y, 10.f);
			angleAdjust = -(normal(frameLast - framePos) * 10);
			drawLine(playerTransform.position.x, playerTransform.position.y, playerTransform.position.x + playerTransform.facing, playerTransform.position.y + playerTransform.facing);


			
	}
	termContext();
}