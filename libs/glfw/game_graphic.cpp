// #include "game_graphic.hpp"

// void myApp();
// {
//     // Создаём окно размером 800x600
//     sf::RenderWindow window(sf::VideoMode(800, 600), "Моя первая SFML программа");
    
//     // Создаём квадрат
//     sf::RectangleShape shape(sf::Vector2f(100, 100));
//     shape.setFillColor(sf::Color::Red);
//     shape.setPosition(350, 250);
    
//     // Основной цикл программы
//     while (window.isOpen())
//     {
//         // Обработка событий
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
        
//         // Очистка окна
//         window.clear();
        
//         // Отрисовка квадрата
//         window.draw(shape);
        
//         // Отображение содержимого окна
//         window.display();
//     }
// }