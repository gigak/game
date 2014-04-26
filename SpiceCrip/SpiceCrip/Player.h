#pragma once
#include "header.h"

class PLAYER {

public:
	float dx,dy;
	FloatRect rect; // вместо 4 координат в одну
	Sprite sprite;

	PLAYER(Texture &image){
		sprite.setTexture(image);
		rect = FloatRect(580,480,79,62);
		sprite.setTextureRect(IntRect (35,42,80,81));
		sprite.setPosition(500,500);
		dx = 0;
		dy = 0;
	}

	void update(float time){

	 rect.left += dx * time;
	 rect.top += dy * time;

	}
};