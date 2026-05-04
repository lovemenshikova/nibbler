#pragma once

#include <SFML/Graphics.hpp>
#include "i_snake_graphic.hpp"

class Graphics : public ISnakeGraphic
{
public:
    explicit Graphics(const Snake& snake);
    ~Graphics() = default;
    
    Graphics() = delete;
    Graphics(const Graphics&) = delete;
    Graphics& operator=(const Graphics&) = delete;
    
    void update() override;
    
private:
    const Snake& _snake;
    sf::RenderWindow *_window;
    unsigned int _winWidth = 800;
    unsigned int _winHeight = 600;
    unsigned int _width = 0;
	    unsigned int _height = 0;
	    unsigned int _scaleWidth = 0;
	    unsigned int _scaleHeight = 0;
	    
    void getLevelInfo();
    void draw();
	void _switch(sf::Vector2<int> index, sf::RenderWindow * _window, sf::Vector2<int> position, sf::Vector2<int> size);
};

extern "C" ISnakeGraphic* glib_instantiate(const Snake& snake);
extern "C" void glib_uninstantiate(ISnakeGraphic*);
