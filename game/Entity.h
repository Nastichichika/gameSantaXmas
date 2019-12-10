#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.h"
#include "AnimationManager.h"
#include "Map.h"
class Entity
{
public:
	float x, y, dx, dy, width, height;
	AnimationManager anim;
	bool life, direction; // 0 - right, 1 - left
	float timer, timerEnd;
	std::string name;
	int health;
	Entity(AnimationManager& anim, int x, int y) {
		this->anim = anim;
		this->x = x;
		this->y = y;
		direction = 0;
		life = true;
		timer = 0;
		timerEnd = 0;
		dx = 0;
		dy = 0;
	}

	virtual void update(float time, Map map) = 0;

	void draw(sf::RenderWindow &window) {
		anim.draw(window, x, y + height);
	}

	sf::FloatRect getRect() {
		return sf::FloatRect(x, y, width, height);
	}

	void option(std::string name, float speed = 0, int health = 10, std::string firstAnim = "")
	{
		this->name = name;
		dx = speed;
		this->health = health;
		if (firstAnim != "") anim.set(firstAnim);
		width = anim.getW();
		height = anim.getH();
	}
};