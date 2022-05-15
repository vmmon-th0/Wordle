#include "wordle.hpp"

int main(int argc, char const *argv[])
{
	if (argc == 2 && access(argv[1], 0) == 0)
	{
		Wordle game(argv[1]);
	}
	else
	{
		std::cerr << "Error : ARGS" << std::endl;
	}
	return 0;
}