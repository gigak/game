#pragma once
#include "header.h"
#include "bullet.h"
#include "anim.hpp"
class Bullet;

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

	//sprite.setPosition(rect.left, rect.top);

	//dx=0;
	}
};


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


void pBack::MoveBack()
{
	sf::Vector2f movement(0.f,0.f);

	movement.y +=speed;
	pSprite.move( movement * time.asSeconds() );
}



int main()
	{
		RenderWindow window (VideoMode (1200, 600), "SpiceCrip"); 


		Texture HeroShip;
		HeroShip.loadFromFile("ships.png"); 

		AnimationManager anim;
		//anim.create("fire", HeroShip, 195, 100, 71, 35, 1, 0.004, 35);

		anim.create("fly", HeroShip, 35, 42, 81, 80, 1, 0.004, 80);

		Texture Cosmos;
		Cosmos.loadFromFile("front.jpg");

		Texture CosmosTwo;
		CosmosTwo.loadFromFile("front.jpg");

		Texture Stars;
		Stars.loadFromFile("stars.png");

		

		PLAYER Ship(HeroShip);


		std::list<Bullet*> bullets; // список указателей пулей
		std::list<Bullet*>::iterator it;


		pBack fBack(Cosmos);
		//pBack sBack(Stars);
		pBack secondBack(CosmosTwo);
		fBack.pSprite.setPosition(0, 0);
		secondBack.pSprite.setPosition(0, -598);
		//sBack.pSprite.setRotation(20);
		//sBack.pSprite.setPosition(300,10);
		Clock clock;
		while (window.isOpen())
			{

				float time = clock.getElapsedTime().asMicroseconds();
				clock.restart();
				time = time/600;
				Event event;

				while (window.pollEvent(event))
					{ 
						if (event.type == Event::Closed)
						window.close();

						if(event.type == Event::KeyPressed)
							if (event.key.code==Keyboard::Space)
								   	bullets.push_back(new Bullet(Ship.sprite.getPosition().x - 73,Ship.sprite.getPosition().y - 30, 1,5) );	
				

					}

				
			
			

				if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) & !(Ship.sprite.getPosition().x < 1)){
					Ship.sprite.move(-0.8*time,0);

				}

				if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) & !(Ship.sprite.getPosition().x > 1070)){
					
					Ship.sprite.move(0.8*time,0);
					
				}

				if ((Keyboard::isKeyPressed(Keyboard::Down)  || Keyboard::isKeyPressed(Keyboard::S))  & !(Ship.sprite.getPosition().y > 540)){
					
					Ship.sprite.move(0,0.8*time);				
				}

				if ((Keyboard::isKeyPressed(Keyboard::Up)  || Keyboard::isKeyPressed(Keyboard::W))  & !(Ship.sprite.getPosition().y < 1) ){Ship.sprite.move(0,-0.8*time);}

					if ( fBack.pSprite.getPosition().y >= 598.f )
						fBack.pSprite.setPosition( 0.f, -598.f );
					if ( secondBack.pSprite.getPosition().y >= 598.f )
						secondBack.pSprite.setPosition( 0.f, -598.f );
				
	

				sf::Music music;
				if (!music.openFromFile("music.ogg"))
					return -1; // error
				music.play();

			


				anim.tick(time);
				//Ship.update(time);
				window.clear();
				fBack.MoveBack();
				secondBack.MoveBack();

				//window.clear(Color::Black);
				window.draw(secondBack.pSprite);
				window.draw(fBack.pSprite);
			//	window.draw(sBack.pSprite);
				window.draw(Ship.sprite);


				for( it = bullets.begin(); it != bullets.end();  )
		        {
				   // ll whatsup = ( *it )->whatsup( enemys, score, time );
			        if( Ship.sprite.getPosition().y < 1 )
					{
						Bullet *deadBullet = *it;
						it = bullets.erase( it );
						delete deadBullet;
					}
			        else
			       {
				        ( *it )->draw( window, time );
				        ++it;
						
			        }
				}




				window.display();

			
   }

   return 0;
}

