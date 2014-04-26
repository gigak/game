#pragma once
#include "Animation.h"

Animation::Animation( Texture &texture, int x, int y, int h, int w, int count, double curSpeed, int step)
{
	curSpeed = curSpeed;
	sprite.setTexture( texture );
	curFrame = 0;

	for( int i = 0; i < count; ++i )
		frames.push_back( IntRect( x, y + i * step, w, h ) );
}

void Animation::startAnim( double time )
{
	curFrame += ( curSpeed * time );
	while( curFrame >= frames.size() )
		curFrame -= frames.size();
	sprite.setTextureRect( frames[ ( int )curFrame ] );
}

bool Animation::endAnim( double time, bool &endAnimFlag )
{
	bool endFlag = 1;
	if( !endAnimFlag )
		curFrame = 0;
	endAnimFlag = 1;
	curFrame += ( curSpeed * time );

	while( curFrame >= frames.size() )
		curFrame -= frames.size();
	sprite.setTextureRect( frames[ ( int )curFrame ] );

	if( ( int )curFrame == frames.size() - 1 )
	{
		endAnimFlag = 0;
		endFlag = 0;
	}

	return endFlag;
}


void AnimationManager::create( string name, Texture &t, int x, int y, int h, int w, int count, double curSpeed, int step)
{
	animMap[ name ] = Animation( t, x, y, h, w, count, curSpeed, step);
	animName = name;
}

void AnimationManager::draw( RenderWindow &window, double x,double y )
{
	animMap[ animName ].sprite.setPosition( x, y );
	window.draw( animMap[ animName ].sprite );
}

void AnimationManager::setAnim( string name )
{
	animName = name;
}

void AnimationManager::startAnim( double time )
{
	animMap[ animName ].startAnim( time );
}

bool AnimationManager::endAnim( double time, bool &endAnimFlag )
{
	return animMap[ animName ].endAnim( time, endAnimFlag );
}