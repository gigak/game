# include <SFML/Graphics.hpp>
 
int main()
{
    // Создаём окно
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Hello World - SFML");
 
    // Основной цикл
    while (App.isOpen())
    {
        // Проверяем события (нажатие кнопки, закрытие окна и т.д.)
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            // если событие "закрытие окна":
            if (Event.type == sf::Event::Closed)
                App.close();
        }
 
        // очищаем экран, и заливаем его синим цветом
        App.clear(sf::Color(0,0,255));
 
        // отображаем на экран
        App.display();
    }
 
    return 0;
}