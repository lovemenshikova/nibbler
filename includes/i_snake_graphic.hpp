#pragma once
# include <queue>
# include "snake.hpp"

class ISnakeGraphic
{
public:
	t_action		glib_action;

	virtual			~ISnakeGraphic(void) = default;
	virtual void	update(void) = 0;
};