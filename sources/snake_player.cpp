#include "snake_player.hpp"
#include "snake.hpp"
#include <iostream>
#include <climits>

Player::Player() :
	score(0)
{}

t_block	Player::_findNextBlock(const t_block block) const
{
	t_block		coord;
	unsigned	wantedBlock;
	Level *		level;

	level = Snake::instance->level;
	wantedBlock = level->getBlock(block) + 1;
	coord = block;

	coord.first += 1;
	if (level->getBlock(coord) == wantedBlock)
		return (coord);

	coord.first -= 2;
	if (coord.first == UINT_MAX)
		coord.first = 0;

	if (level->getBlock(coord) == wantedBlock)
		return (coord);

	coord.first = block.first;
	coord.second += 1;
	if (level->getBlock(coord) == wantedBlock)
		return (coord);

	coord.second -= 2;
	if (coord.second == UINT_MAX)
		coord.second = 0;

	if (level->getBlock(coord) == wantedBlock)
		return (coord);

	coord.first = UINT_MAX;

	return (coord);
}

void	Player::_moveBlock(t_block & block, t_orient orient) const
{
	switch (orient)
	{
		case NORTH:
			block.second -= 1;
			break;
		case WEST:
			block.first += 1;
			break;
		case SOUTH:
			block.second += 1;
			break;
		case EAST:
			block.first -= 1;
	}
}

void	Player::spawn()
{
	unsigned	i;
	Level *		level;
	t_block		block;

	orientation = WEST;
	pendingOrientation = orientation;
	size = PLAYER_DEFAULT_SIZE;
	pendingNom = 0;

	level = Snake::instance->level;

	head.first = level->spawn.first;
	head.second = level->spawn.second;
	block = head;

	// Reversing orientation to place the snake's body
	orientation = static_cast<t_orient>((orientation + 2) % 4);

	i = 0;
	while (i < size)
	{
		if (level->getBlock(block) != BLOCK_NONE)
			throw Level::BadMapException();

		level->setBlock(block, BLOCK_HEAD + i);
		_moveBlock(block, orientation);
		i++;
	}

	// Setting original orientation back
	orientation = static_cast<t_orient>((orientation + 2) % 4);

	Snake::instance->generateNom();
}

void	Player::eat()
{
	// unsigned	random;

	// random = rand() % MULTINOM_RATE;
	pendingNom++;
	size++;
	score++;
	Snake::instance->generateNom();
}

bool	Player::move()
{
	t_block		prevBlock;
	t_block		nextBlock;
	unsigned	i;
	Level *		level;

	level = Snake::instance->level;

	nextBlock = head;
	_moveBlock(head, orientation);
	prevBlock = head;

	switch (level->getBlock(head))
	{
		case BLOCK_NONE:
			break;
		case BLOCK_NOM:
			eat();
			break;
		default:
			return false;
	}

	i = BLOCK_HEAD - 1;

	while (level->getBlock(nextBlock) > i)
	{
		level->setBlock(prevBlock, level->getBlock(nextBlock));
		prevBlock = nextBlock;
		nextBlock = _findNextBlock(prevBlock);
		i++;
	}

	if (pendingNom > 0)
	{
		pendingNom--;
		level->setBlock(prevBlock, i + 1);
	}
	else
		level->setBlock(prevBlock, BLOCK_NONE);

	return true;
}

void	Player::changeOrientation(t_orient orient)
{
	if (orientation % 2 != orient % 2)
		pendingOrientation = orient;
	else
		pendingOrientation = orientation;
}
