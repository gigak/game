#include "bullet.h"

Bullet::Bullet( double x, double y, int damage, int speed )
{
	
	xPos = x + 80;
	yPos = y + 45;
	this->damage = damage;
	this->speed = speed;
	
	t.loadFromFile( "fire.png" );
	sprite.setTexture( t );
	sprite.setTextureRect( IntRect( 0, 0, 70, 32 ) );
	sprite.setPosition( x, y );
}

void Bullet::draw( RenderWindow &wnd, double time )
{
	yPos -= ( speed * time / 30 );
	sprite.setPosition( xPos, yPos );
	wnd.draw( sprite );
}
