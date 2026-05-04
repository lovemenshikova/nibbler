#include <iostream>
#include <sys/time.h>
#include "snake_utils.hpp"

double	Util::getTime()
{
	static time_t	beginning;
	struct timeval	tod;
	double			ret;

	gettimeofday(&tod, NULL);
	if (beginning == 0)
		beginning = tod.tv_sec;
	ret = static_cast<double>(tod.tv_sec - beginning);
	ret += static_cast<double>(tod.tv_usec) / 1000000;
	return (ret);
}

int		Util::die(std::string message)
{
	std::cout << message << std::endl;
	exit(EXIT_FAILURE);
}