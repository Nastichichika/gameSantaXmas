#include "Animation.h"

Animation::Animation() {
	isPlaying = true;
	flip = false;
	loop = true;
}
void Animation::tick(float time) {
	if (!isPlaying) return;
	currentFrame += speed * time;
	if (currentFrame > frames.size()) {

		currentFrame -= frames.size();
		if (!loop) { 
			isPlaying = false; 
			return; 
		}
	}
	int num = currentFrame;
	if (flip) sprite.setTextureRect(framesFlip[num]);
	else sprite.setTextureRect(frames[num]);
}
