// #include <iostream>
// #include <dlfcn.h>
// #include "snake.hpp"

// int main()
// {
//     Snake snake;

//     std::cout << "start snake\n";

//     snake.loadLibrary("/Users/vellie/Downloads/nibbler/libs/sfml/library_2.so");
//     snake.loadLevel(0);
//     return 0;
// }


#include <iostream>
#include "snake.hpp"
#include "snake_lib_handler.hpp"
#include "snake_utils.hpp"

#define OPTION_WIDTH	0
#define OPTION_HEIGHT	1
#define OPTION_LEVEL	2
#define OPTION_LIB		3

// static void	processOptions(unsigned ac, const char * const * av, char ** options)
// {
// 	for (unsigned i = 1; i < ac - 1; i++)
// 	{
// 		if (strcmp(av[i], "-level") == 0 && av[i + 1][0] != '-')
// 			options[OPTION_LEVEL] = strdup(av[++i]);
// 		else if (strcmp(av[i], "-lib") == 0 && av[i + 1][0] != '-')
// 			options[OPTION_LIB] = strdup(av[++i]);
// 		else if (strcmp(av[i], "-w") == 0 && av[i + 1][0] != '-')
// 			options[OPTION_WIDTH] = strdup(av[++i]);
// 		else if (strcmp(av[i], "-h") == 0 && av[i + 1][0] != '-')
// 			options[OPTION_HEIGHT] = strdup(av[++i]);
// 		else
// 		{
// 			std::cout << "Invalid option name or value: " << av[i] << std::endl;
// 			exit(EXIT_FAILURE);
// 		}
// 	}
// }

// static void	checkOptions(const char * const * options)
// {
// 	if (options[OPTION_LIB] == NULL)
// 		Util::die("-lib needs to be specified.");
// 	else if (options[OPTION_LEVEL] == NULL &&
// 		(options[OPTION_WIDTH] == NULL || options[OPTION_HEIGHT] == NULL))
// 		Util::die("-level or -w and -h need to be specified.");
// }

int		main()
{
	// char *			options[4] = { NULL };
	Snake			snake;

	// processOptions(ac, av, options);
	// checkOptions(options);
	std::cout << "I am in the start of main\n";

	snake.loadLibrary("/Users/liubov/projects/nibbler/nibbler/nibbler/libs/sfml/library_2.so");

	snake.loadLevel(600, 800);

	snake.launch();

	return (EXIT_SUCCESS);
}
// setx PATH "$env:PATH;Users/liubov/projects/nibbler/nibbler/nibbler/libs/sfml/"
