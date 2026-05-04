#pragma once
# include <SFML/Graphics.hpp>

class SDrawer {
public:
	static void		drawCell(sf::RenderWindow * renderer, sf::Vector2f position, sf::Vector2f size);
	static void		drawFull(sf::RenderWindow * renderer, sf::Vector2f position, sf::Vector2f size, sf::Color color);
private:
	SDrawer(void);
	SDrawer(SDrawer const &);
	~SDrawer(void);

	SDrawer &	operator=(SDrawer const &);
};