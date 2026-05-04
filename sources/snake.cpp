#include <iostream>
#include <unistd.h>
#include "snake.hpp"
#include "snake_lib_handler.hpp"
#include "snake_utils.hpp"

Snake *	Snake::instance = NULL;

Snake::Snake(void) :
	level(NULL),
	speed(DEFAULT_SPEED),
	paused(false),
	clockCountdown(0),
	stop(false)
{
	instance = this;
	srand(time(NULL));
}

Snake::~Snake()
{
	if (level != NULL)
		delete level;
	if (ghandler != NULL)
		delete ghandler;
}

void	Snake::loadLevel(const std::string pathname)
{
	if (level != NULL)
		delete level;

	try
	{
		level = new Level(pathname);
		player.spawn();
	}
	catch (Level::BadMapException & e)
	{
		std::cout << "Error while loading the map: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	catch (std::exception & e)
	{
		std::cout << "An unexpected error has occured." << std::endl;
		exit(EXIT_FAILURE);
	}

}

void	Snake::loadLevel(unsigned width, unsigned height)
{
	if (level != NULL)
		delete level;

	try
	{
		level = new Level(width, height);
		player.spawn();
	}
	catch (Level::BadMapException & e)
	{
		std::cout << "Error while loading the map: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	catch (std::exception & e)
	{
		std::cout << "An unexpected error has occured." << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	Snake::loadLibrary(const std::string name)
{
    std::cout << "loadLibrary 1\n";
	if (ghandler != NULL)
		delete ghandler;
    std::cout << "loadLibrary 2\n";
	ghandler = new SnakeLibHandler(*this);
    std::cout << "loadLibrary 3\n";
	try
	{
        std::cout << "loadLibrary 4\n";
		ghandler->loadLibrary(name);
	}
	catch (SnakeLibHandler::LibraryNotFoundException & e)
	{
		std::cout << "Library error: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	catch (SnakeLibHandler::BadLibraryException & e)
	{
		std::cout << "Library error: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

void	Snake::removeNoms()
{
	t_block	block;

	for (block.first = 0; block.first < level->width; block.first++)
	{
		for (block.second = 0; block.second < level->height; block.second++)
		{
			if (level->getBlock(block) == BLOCK_NOM)
				level->setBlock(block, BLOCK_NONE);
		}
	}
}

void	Snake::generateNom(unsigned count)
{
	while (count-- != 0)
		generateNom();
}

void	Snake::generateNom()
{
	unsigned	random;
	unsigned	i;
	t_block		block;

	random = rand() % (level->height * level->width);
	i = 0;

	while (1)
	{
		block = { 0, 0 };
		while (block.second < level->height)
		{
			block.first = 0;
			while (block.first < level->width)
			{
				if (level->getBlock(block) == BLOCK_NONE)
				{
					if (i == random)
						return level->setBlock(block, BLOCK_NOM);
					i++;
				}
				block.first++;
			}
			block.second++;
		}
	}
}

void	Snake::launch()
{
	stop = false;
	while (!stop)
		update();

}

void	Snake::update()
{
	static float	lastTime;
	float			currentTime;

	if (lastTime == 0 || paused)
		lastTime = Util::getTime();

	SnakeLibHandler::instance->update();
	handleAction();

	if (paused)
		return ;

	if (clockCountdown <= 0)
	{
		player.orientation = player.pendingOrientation;

		if (player.move() == false)
			return gameOver();

		speed = std::max<float>(speed - speed / SPEED_INC, MAX_SPEED);
		while (clockCountdown <= 0)
			clockCountdown += speed;
	}

	currentTime = Util::getTime();
	clockCountdown -= currentTime - lastTime;
	lastTime = currentTime;
}

void	Snake::gameOver()
{
	std::cout << "You lost with a score of " << player.score << "." << std::endl;
	stop = true;
}

void	Snake::handleAction()
{
	switch (SnakeLibHandler::instance->glib_action)
	{
		case UP:
			paused = false;
			player.changeOrientation(NORTH);
			break;
		case DOWN:
			paused = false;
			player.changeOrientation(SOUTH);
			break;
		case LEFT:
			paused = false;
			player.changeOrientation(WEST);
			break;
		case RIGHT:
			paused = false;
			player.changeOrientation(EAST);
			break;
		case PAUSE:
			paused = true;
			break;
		case LIB1:
			paused = true;
			loadLibrary("libs/sfml/library_2.so");
			break;
		case LIB2:
			paused = true;
			loadLibrary("lib2/lib2.so");
			break;
		case LIB3:
			paused = true;
			loadLibrary("lib3/lib3.so");
			break;
		case QUIT:
			stop = true;
		case NONE:
			break;
	}

	SnakeLibHandler::instance->glib_action = NONE;
}

void	Snake::dump(bool humanize) const
{
	unsigned	x;
	unsigned	y;

	std::cout << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "Size: " << player.size << std::endl;
	std::cout << "Pending nom: " << player.pendingNom << std::endl;
	std::cout << std::endl;

	if (humanize)
	{
		y = 0;
		while (y < level->height)
		{
			std::cout << "   ";
			x = 0;
			while (x < level->width)
			{
				switch (level->map[y][x])
				{
					case BLOCK_NONE:
						std::cout << ' ';
						break;
					case BLOCK_WALL:
						std::cout << "\u25AF";
						break;
					case BLOCK_NOM:
						std::cout << "x";
						break;
					case BLOCK_HEAD:
						std::cout << 'O';
						break;
					default:
						std::cout << 'o';
				}
				std::cout << ' ';
				x++;
			}

			std::cout << std::endl;
			y++;
		}
	}
	else
	{
		y = 0;
		while (y < level->height)
		{
			x = 0;
			while (x < level->width)
			{
				std::cout << level->map[y][x] << ' ';
				x++;
			}

			std::cout << std::endl;
			y++;
		}
	}

	std::cout << "---------------" << std::endl;
	std::cout << std::endl;
}
