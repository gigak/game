#pragma once
#include "header.h"

class Enemy {

public:
	float dx,dy;
	int level;
	double damage, speed, health;
	FloatRect rect; // вместо 4 координат в одну
	Sprite sprite;

	Enemy(Texture &image){
		sprite.setTexture(image);
		rect = FloatRect(580,480,79,62);
		sprite.setTextureRect(IntRect (35,42,80,81));
		sprite.setPosition(500,500);
		dx = 0;
		dy = 0;
	}

	int whatlevel(int count){

		switch ( count )
			  {
				 case '1':
					health = 5;
					speed = 400;
					damage = 5;
					level = 1;
					break;

				 case '2':
					health = 10;
					speed = 450;
					damage = 7;
					level = 2;
					break;

				 case '3':
					health = 15;
					speed = 470;
					damage = 10;
					level = 3;
					break;

				 case '4':
					health = 20;
					speed = 480;
					damage = 7;
					level = 4;
					break;
				 case '5':
					health = 20;
					speed = 500;
					damage = 11;
					level = 5;
					break;

				 default:
					health = 5;
					speed = 400;
					damage = 5;
					level = 1;
			  }
	}

	void update(float time){

	 rect.left += dx * time;
	 rect.top += dy * time;

	}
};


class whatEnemy{

	int level;

public:

	whatEnemy(){}
	whatEnemy( int level);

	int getLevel();
	void upgrade();
};

class Enemy{

	int speed,damage,health;
	int h,w;

	double xPos, yPos;
	string curAnim;
	AnimationManager startAnim;
	Texture texture;
	Sprite sprite;
	whatEnemy enemy;

public:

	Enemy(){}
	virtual bool move( double time ) = 0;
	virtual void shift( double time ) = 0;
	void draw( RenderWindow &window, double time);
	void create ( whatEnemy enemy);
	double xPos();
	double yPos();
	int damage();
	int getLevel();
	int getH();
	int getW();
	bool flag();
	
};


class firstShip: public Enemy{

public:

	firstShip( whatEnemy enemy );

	bool move ( double time );
	void shift ( double time) {}
};