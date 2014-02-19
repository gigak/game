# include <SFML/Graphics.hpp>

using namespace sf;

const int H = 12;
const int W = 40;



int main()
	{
		RenderWindow window (VideoMode (1100, 700), "SpiceCrip"); // —оздаем окно 1100*700 и title = SpiceCrip
		Texture HeroShip; // текстурка
		HeroShip.loadFromFile("ships.png"); // грузим изображение
   
		/* «адаем координаты из спрайта нашего кораблика */
		Sprite Hero;
		Hero.setTexture(HeroShip);
		Hero.setTextureRect (IntRect (38,42,79,62));
		Hero.setPosition(70,62);
   
	
		Clock clock;
		while (window.isOpen())
			{

				float time = clock.getElapsedTime().asMicroseconds();
				clock.restart();
				time = time/800;
				Event event;

				while (window.pollEvent(event))
					{ 
						if (event.type == Event::Closed)
						window.close();
					}


				if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)){Hero.move(-0.8*time,0);}

				if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D) ){ Hero.move(0.8*time,0);}

				if (Keyboard::isKeyPressed(Keyboard::Down)  || Keyboard::isKeyPressed(Keyboard::S) ){Hero.move(0,0.8*time);}

				if (Keyboard::isKeyPressed(Keyboard::Up)  || Keyboard::isKeyPressed(Keyboard::W) ){Hero.move(0,-0.8*time);}
		  

				window.clear(Color::Black);
				window.draw(Hero);
				window.display();
   }

   return 0;
}