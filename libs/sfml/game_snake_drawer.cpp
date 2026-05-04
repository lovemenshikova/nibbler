#include "game_snake_drawer.hpp"

void		SDrawer::drawCell(sf::RenderWindow * renderer, sf::Vector2f position, sf::Vector2f size)
{
	sf::RectangleShape rect(size);

	rect.setPosition(position);
	rect.setFillColor(sf::Color::Black);
	rect.setOutlineColor(sf::Color(150, 150, 150));
	rect.setOutlineThickness(0.5);
	renderer->draw(rect);
}

void		SDrawer::drawFull(sf::RenderWindow * renderer, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
	sf::RectangleShape rect(size);

	rect.setPosition(position);
	rect.setFillColor(color);
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(0.5);
	renderer->draw(rect);
}
