#include "Bullet.h"

Bullet::Bullet(AnimationManager &a, int x, int y, bool direction) :Entity(a, x, y) {
	option("Bullet", 0.3, 10, "move");
	if (direction) dx = -0.3;
}

void Bullet::update(float time, Map map) {
	x += dx * time;
	for (int i = y / 16; i < (y + height) / 16; i++)
		for (int j = x / 16; j < (x + width) / 16; j++)
			if (map.TileMap[i][j] == 'B') {
				dx = 0;
				life = false;
			}
	anim.tick(time);
}

