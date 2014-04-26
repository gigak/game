#pragma once
#include "header.h"
//#include "Classes.h"
//#include "Enemy.h"

class Bullet
{
	double xPos, yPos;
	double damage, speed;
	Sprite sprite;
	Texture t;

public:

	Bullet(){}
	Bullet( double x, double y, int damage, int speed );
	void draw( RenderWindow &wnd, double time );

};
