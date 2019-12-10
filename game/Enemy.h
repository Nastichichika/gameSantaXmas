#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:

	Enemy(AnimationManager&, int, int);
	void update(float, Map);
};

