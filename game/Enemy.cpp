#include "Enemy.h"

Enemy::Enemy(AnimationManager& a, int x, int y) :Entity(a, x, y) {
	option("Enemy", 0.01, 15, "move");
}

void Enemy::update(float time, Map map) {
	dx *= -1;
	x += dx*time;
	timer += time;
	if (timer > 3200) {
		dx *= -1;
		anim.flip(1);
		timer = 0;
	}
	if (health <= 0) {
		anim.set("dead"); dx = 0;
		timerEnd += time;
		if (timerEnd > 4000) life = false;
	}
	anim.tick(time);
}
