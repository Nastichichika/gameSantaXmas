#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
class Animation
{
public:
	std::vector<sf::IntRect> frames, framesFlip;
	float currentFrame = 0, speed;
	bool flip, isPlaying, loop;
	sf::Sprite sprite;
	Animation();
	void tick(float);
};

