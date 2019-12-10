#include "AnimationManager.h"

void AnimationManager::create(sf::String currentAnimation, sf::Texture& t, int x, int y, int width, int height, float speed, int count, int step, bool loop) {
	Animation a;
	a.loop = loop;
	a.speed = speed;
	a.sprite.setTexture(t);
	a.sprite.setOrigin(0, height);
	for (int i = 0; i < count; i++) {
		a.frames.push_back(sf::IntRect(x + i * step, y, width, height));
		a.framesFlip.push_back(sf::IntRect(x + i * step + width, y, -width, height));
	}
	animationList.insert(std::pair< sf::String, Animation>(currentAnimation, a));

}
void AnimationManager::draw(sf::RenderWindow &window, int x, int y) {
	animationList[currentAnimation].sprite.setPosition(x, y);
	window.draw(animationList[currentAnimation].sprite);
}
void AnimationManager::set(sf::String name) { 
	currentAnimation = name; 
	animationList[currentAnimation].flip = 0;
}
void AnimationManager::flip(bool check) { 
	animationList[currentAnimation].flip = check; 
}
void AnimationManager::tick(float time) { 
	animationList[currentAnimation].tick(time); 
}
void AnimationManager::pause() { 
	animationList[currentAnimation].isPlaying = false; 
}
void AnimationManager::play() { 
	animationList[currentAnimation].isPlaying = true; 
}
bool AnimationManager::isPlaying() { 
	return animationList[currentAnimation].isPlaying; 
}

float AnimationManager::getH() { 
	return animationList[currentAnimation].frames[0].height; 
}

float AnimationManager::getW() { 
	return animationList[currentAnimation].frames[0].width; 
}

