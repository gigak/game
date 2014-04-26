#pragma once
#include "header.h"

class Animation
{

private:
	vector< IntRect > frames;
	double curFrame, curSpeed;

public:
	
	Sprite sprite;

	Animation(){};
	Animation( Texture &texture, int x, int y, int h, int w, int count, double curSpeed, int step);

	void startAnim( double time );
	bool endAnim( double time, bool &endAnimFlag );
};

class AnimationManager
{
	string animName;
	map< string, Animation > animMap;

public:

    AnimationManager(){};

	void create( string name, Texture &t, int x, int y, int height, int width, int count, double curSpeed, int step);
    void draw( RenderWindow &window, double x,double y );
    void setAnim( string name );
	void startAnim( double time );
	bool endAnim( double time, bool &endAnimFlag );
};