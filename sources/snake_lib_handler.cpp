#include <dlfcn.h>
#include <iostream>
#include "snake_lib_handler.hpp"

ISnakeGraphic *		SnakeLibHandler::instance = NULL;

SnakeLibHandler::SnakeLibHandler(const Snake & s) :
	_snake(s)
{}

SnakeLibHandler::~SnakeLibHandler()
{
	_uninstantiate(instance);
	dlclose(_handler);
}

void			SnakeLibHandler::loadLibrary(std::string name)
{
	t_sym_instantiate	instantiate;

	_handler = dlopen(name.c_str(), RTLD_NOW);

	if (_handler == NULL)
	{
		std::cout << dlerror() << std::endl;
		throw LibraryNotFoundException();
	}

	instantiate = reinterpret_cast<t_sym_instantiate>(loadSymbol("glib_instantiate"));
	_uninstantiate = reinterpret_cast<t_sym_uninstantiate>(loadSymbol("glib_uninstantiate"));
	instance = instantiate(_snake);
}

void *		SnakeLibHandler::loadSymbol(const std::string name)
{
	const char *	dlsym_error;
	void *			symbol;

	dlerror();
	symbol = dlsym(_handler, name.c_str());
	dlsym_error = dlerror();

	if (dlsym_error)
		throw BadLibraryException();

	return symbol;
}

const char *	SnakeLibHandler::LibraryNotFoundException::what() const throw()
{
	return "Library not found.";
}

const char *	SnakeLibHandler::BadLibraryException::what() const throw()
{
	return "Bad graphic library.";
}
