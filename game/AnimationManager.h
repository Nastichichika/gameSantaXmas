#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
class AnimationManager
{
public:
	sf::String currentAnimation;
	std::map<sf::String, Animation> animationList;
	AnimationManager() {}
	void create(sf::String, sf::Texture&, int, int, int, int, float, int, int, bool);
	void draw(sf::RenderWindow&, int x = 0, int y = 0);
	void set(sf::String);
	void flip(bool);
	void tick(float);
	void pause();
	void play();
	bool isPlaying();
	float getH();
	float getW();
	~AnimationManager() {
		animationList.clear();
	}
};

