#pragma once

# include <string>
# include <exception>
# include "snake.hpp"
# include "i_snake_graphic.hpp"

typedef ISnakeGraphic *	(*t_sym_instantiate)(const Snake &);
typedef void		(*t_sym_uninstantiate)(ISnakeGraphic *);

class SnakeLibHandler
{
protected:
	const Snake &		_snake;
	void *				_handler;
	t_sym_uninstantiate	_uninstantiate;

public:
	class LibraryNotFoundException : public std::exception
	{
	public:
		virtual const char *	what() const throw();
	};

	class BadLibraryException : public std::exception
	{
	public:
		virtual const char *	what() const throw();
	};

	SnakeLibHandler(const Snake &);
	~SnakeLibHandler();

	static ISnakeGraphic *	instance;

	void				loadLibrary(std::string);
	void *				loadSymbol(const std::string);
};