#pragma once

# include <string>
# include "snake_level.hpp"
# include "snake_player.hpp"

# define DEFAULT_SPEED	1.0f
# define SPEED_INC		30.0f
# define MAX_SPEED		0.10f
# define MULTINOM_RATE	10

class SnakeLibHandler;

typedef enum		e_action
{
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	PAUSE,
	QUIT,
	LIB1,
	LIB2,
	LIB3
}					t_action;

class Snake
{
public:
	static Snake *		instance;
	Level *				level;
	Player				player;
	float				speed;
	bool				paused;
	float				clockCountdown;
	bool				stop;
	SnakeLibHandler *	ghandler{NULL};

	Snake();
	~Snake();

	void				loadLevel(unsigned, unsigned);
	void				loadLevel(const std::string);
	void				loadLibrary(const std::string);
	void				gameOver();
	void				generateNom();
	void				generateNom(unsigned);
	void				removeNoms();
	void				launch();
	void				update();
	void				handleAction();
	void				dump(bool = false) const;
};
