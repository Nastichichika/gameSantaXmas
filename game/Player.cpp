#include "Player.h"
#include <iostream>

Player::Player(AnimationManager& a, int x, int y) :Entity(a, x, y) {
	option("Player", 0, 5, "stay");
	STATE = stay; 
	hit = false;
}

void Player::update(float time, Map map) {
	keyCheck();
	Animation(time);
	if(!onGround) dy += 0.0005*time;
	x += dx * time;
	onGround = false;
	collision(1, map);
	y += dy * time;
	collision(0, map);
}

void Player::collision(bool check, Map map) {
	for (int i = y / 16; i < (y + height) / 16; i++)
		for (int j = x / 16; j < (x + width) / 16; j++)
			if (map.TileMap[i][j] == 'B') {
				if (check) {
					if (dx > 0) x = j * 16 - width;
					if (dx < 0) x = j * 16 + 16;
				}
				else {
					if (dy > 0) {
						y = i * 16 - height;
						dy = 0;
						onGround = true;
					}
					if (dy < 0) {
						y = i * 16 + 16;
						dy = 0;
					}
				}
			}
}
void Player::Animation(float time) {
	if (STATE == stay) anim.set("stay");
	if (STATE == walk) anim.set("walk");
	if (STATE == jump) anim.set("jump");
	if (shoot) {
		anim.set("gift");
	}
	if (hit) {
		timer += time;
		if (timer > 1000) { 
			hit = false; timer = 0; 
		}
		//anim.set("hit");
	}
	if (direction) anim.flip(1);
	anim.tick(time);
}
void Player::keyCheck() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		direction = 1;
		dx = -0.1;
		STATE = walk;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		direction = 0;
		dx = 0.1;
		STATE = walk;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if ((STATE == walk || STATE == stay) && onGround) {
			dy = -0.2;
			STATE = jump;
			onGround = false;
		}
	}
	if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
		dx = 0;
		if (STATE == walk || dy >= 0) {
			STATE = stay;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		shoot = true;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		shoot = false;
}

