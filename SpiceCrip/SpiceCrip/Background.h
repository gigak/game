#pragma once
#include "header.h"

class pBack{
public:
	//int x,y;
	double speed;
	sf::Time time;
	//FloatRect pRect;
	sf::Sprite pSprite;


	pBack(Texture &image) { pSprite.setTexture(image); speed = 400; time = sf::seconds(1/6000.f); }
	void MoveBack();

	

};