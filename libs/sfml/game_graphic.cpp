#include <iostream>
#include "game_graphic.hpp"
#include "game_snake_drawer.hpp"

Graphics::Graphics(const Snake& s) : _snake(s)
{
    // sf::ContextSettings settings;
    // settings.antiAliasingLevel = 8;
    _window = new sf::RenderWindow(
        sf::VideoMode({800, 600}),
        "SFML Snake"
    );
}

void Graphics::update()
{
    std::optional<sf::Event> event;
    while ((event = _window->pollEvent())) {
        
        if (event->is<sf::Event::Closed>()) {
            _window->close();
            glib_action = QUIT;
        }
        else if (event->is<sf::Event::KeyPressed>()) {
            auto tmp = event->getIf<sf::Event::KeyPressed>()->code;
            switch (tmp) {
                case sf::Keyboard::Key::Escape:
                    glib_action = QUIT;
                    break;
                case sf::Keyboard::Key::P:
                    glib_action = PAUSE;
                    break;
                case sf::Keyboard::Key::Up:
                    glib_action = UP;
                    break;
                case sf::Keyboard::Key::Down:
                    glib_action = DOWN;
                    break;
                case sf::Keyboard::Key::Left:
                    glib_action = LEFT;
                    break;
                case sf::Keyboard::Key::Right:
                    glib_action = RIGHT;
                    break;
                case sf::Keyboard::Key::Numpad1:
                    glib_action = LIB1;
                    break;
                case sf::Keyboard::Key::Numpad3:
                    glib_action = LIB3;
                    break;
                default:
                    break;
            }
        }
    }
    draw();
}

void Graphics::getLevelInfo()
{
    _width = _snake.level->width;
    _height = _snake.level->height;
    _scaleWidth = _winWidth / _width;
    _scaleHeight = _winHeight / _height;
}

void Graphics::draw()
{
	getLevelInfo();
	_window->clear();

	unsigned int i;
	unsigned int j;
	for (i = 0; i < _snake.level->width; i++)
	{
		for(j = 0; j < _snake.level->height; j++)
		{
			_switch(
				sf::Vector2<int>(i, j),
				_window,
				sf::Vector2<int>(i * _scaleWidth, j * _scaleHeight),
				sf::Vector2<int>(_scaleWidth, _scaleHeight)
			);
		}
	}

	_window->display();
}

void Graphics::_switch(sf::Vector2<int> index, sf::RenderWindow * _window, sf::Vector2<int> position, sf::Vector2<int> size)
{
	switch (_snake.level->map[index.y][index.x])
	{
		case BLOCK_NONE:
			SDrawer::drawCell(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y));
			break;
		case BLOCK_WALL:
			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(200, 200, 200));
			break;
		case BLOCK_NOM:
			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(242, 43, 0));
			break;
		case BLOCK_HEAD:
			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(76, 153, 0));
			break;
		default:
			SDrawer::drawFull(_window, sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y), sf::Color(204, 102, 0));
	}
}


ISnakeGraphic* glib_instantiate(const Snake& s)
{
    return new Graphics(s);
}

void glib_uninstantiate(ISnakeGraphic* g)
{
    delete g;
}
