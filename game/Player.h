#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "AnimationManager.h"
#include "Entity.h"

class Player : public Entity
{
public:
	bool hit, shoot, onGround;
	enum {stay, walk, jump} STATE;
	Player(AnimationManager&, int, int);
	void keyCheck();
	sf::FloatRect rect;
	sf::Sprite sprite;
	float currentFrame;
	void collision(bool, Map);
	void Player::Animation(float);
	void update(float, Map);
};

