#include "Background.h"

void pBack::MoveBack()
{
	sf::Vector2f movement(0.f,0.f);

	movement.y +=speed;
	pSprite.move( movement * time.asSeconds() );
}
