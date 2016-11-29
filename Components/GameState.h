#pragma once

#include "PlayerShip.h"
#include "Camera.h"
#include "Asteroid.h"
#include "Walls.h"
#include "Bullets.h"
/*
Basic structure of an application state.
Whether it's a menu, game, pause, victory screen;
the same basic concepts all work within a
finite state machine.
We don't need /all/ of them for /every/ state,
but it's generally useful to keep these steps in mind
when creating any kind of object.
init
- Called once at application start.
- Used for loading resources (like textures).
- See 'lazy initialization.'
play/exec/enter/start
- Called once as we transition into an application state.
- Used to reset the logic of the state (ie. new game, reset timers).

exit/stop
- Called once as we transition out of a state.
- Used for bookkeeping, not inherently useful.
term
- Called once at application shutdown
- Used to free resources (like textures).

step/update/tick
- Called once every frame.
- Used to update logic.
- Usually we decide to transition to other states from here.
draw/render
- Called once every frame.
- Used to issue draw commands.
*/

const int MAX_WALLS = 16;
const int MAX_BULLETS = 500;

class GameState
{

public:
	Walls walls[MAX_WALLS];
	Bullets bullets[MAX_BULLETS];
	PlayerShip player;
	Camera camera;
	Asteroid asteroid[2];
	int shots = 0;
	int type;
	bool press = false;
	int ammotype = 1;
	unsigned int ammoColor = RED;

	void init();
	void play();				  //
	void update(float deltaTime); // equivalent of step
	void draw();

	/// If you're courageous!
	void spawnBullet(Transform t, int type, int sig);
};