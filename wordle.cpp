#include "wordle.hpp"

Wordle::Wordle()
{
}

Wordle::Wordle(const std::string& words_file)
{
	std::ifstream 	i_file(words_file);
	std::string 	buff_line;
	srand (time(NULL));

	if (!i_file.is_open())
	{
		std::cerr << "Could not open the file" << std::endl;
		return ;
	}
	while (getline(i_file, buff_line))
	{
		this->dict.push_back(buff_line);
	}
	i_file.close();
	gameHandler();
}

Wordle::~Wordle()
{
}

void Wordle::display_dict()
{
	for (std::vector<std::string>::iterator it = dict.begin(); it != dict.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}

void Wordle::display_board()
{
	for (std::vector<std::string>::iterator it = board.begin(); it != board.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void Wordle::presentation() const
{
	std::cout << MAGENTA;
	std::cout <<	 "__          ______  _____  _____  _      ______" 			<< std::endl;
	std::cout << 	 "\\ \\        / / __ \\|  __ \\|  __ \\| |    |  ____|" 	<< std::endl;
	std::cout <<  	 " \\ \\  /\\  / / |  | | |__) | |  | | |    | |__   "		<< std::endl;
	std::cout << 	 "  \\ \\/  \\/ /| |  | |  _  /| |  | | |    |  __|  "		<< std::endl;
	std::cout <<     "   \\  /\\  / | |__| | | \\ \\| |__| | |____| |____ "		<< std::endl;
	std::cout <<     "    \\/  \\/   \\____/|_|  \\_\\_____/|______|______|"	<< std::endl;
	std::cout << RESET << std::endl << std::endl;
	std::cout << "Total words available : " << dict.size() << std::endl;
}

void Wordle::initGame()
{
	presentation();
	for (int i = 0; i < 5; i++)
	{
		this->board.push_back(std::string(5, '-'));
	}
	this->secret_word = this->dict[rand() % this->dict.size()];
}

std::string Wordle::designRow(std::string::iterator it, std::string::iterator it2, std::string &buff_line) const
{
	std::string row;
	while (it != buff_line.end() && it2 != secret_word.end())
	{
		if (*it == *it2)
			row += std::string(GREEN) += std::string(1, *it) += std::string(RESET);
		else if (std::find(secret_word.begin(), secret_word.end(), *it) != secret_word.end())
			row += std::string(YELLOW) += std::string(1, *it) += std::string(RESET);
		else
			row += std::string(WHITE) += std::string(1, *it) += std::string(RESET);
		it++, it2++;
	}
	for (int i = buff_line.size(); i < 5; i++)
	{
		row += "-";
	}
	return row;
}

void Wordle::gameHandler()
{
	std::string buff_line;

	initGame();
	for (int i = 0; i < 6 && !std::cin.eof(); i++)
	{
		display_board();
		std::cout << "Input : " << std::endl;
		while (buff_line.size() != 5)
		{
			std::getline(std::cin, buff_line);
		}
		board[i] = designRow(buff_line.begin(), secret_word.begin(), buff_line); 
		if (!secret_word.compare(buff_line))
		{
			display_board();
			std::cout << CGREEN("Congratulations !") << std::endl;
			return ;
		}
		buff_line.clear();
	}
	std::cout << CRED("Game over") << std::endl;
}