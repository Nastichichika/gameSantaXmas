#pragma once
#include "Entity.h"


class Bullet :public Entity
{
public:
	Bullet(AnimationManager &a, int x, int y, bool direction);
	void update(float time, Map map);
};

