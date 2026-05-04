#pragma once
# include <vector>
# include "snake_level.hpp"

# define PLAYER_DEFAULT_SIZE	3

typedef enum	e_orient
{
	NORTH = 0,
	EAST,
	SOUTH,
	WEST
}				t_orient;

class Player
{
protected:
	t_block				_findNextBlock(const t_block) const;
	void				_moveBlock(t_block &, t_orient) const;

public:
	t_block				head;
	t_orient			orientation;
	t_orient			pendingOrientation;
	unsigned			size;
	unsigned			pendingNom;
	unsigned			score;

	Player();

	void				changeOrientation(t_orient);
	void				spawn();
	bool				move();
	void				eat();
};