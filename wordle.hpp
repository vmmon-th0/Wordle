#ifndef WORDLE_HPP
#define WORDLE_HPP

#include <string>
#include <vector>
#include <time.h>
#include <iostream>
#include <fcntl.h>
#include <fstream>
#include <unistd.h>
#include "rainbow.hpp"

#define CRED(x)		RED x RESET
#define CYELLOW(x)	YELLOW x RESET
#define CWHITE(x)	WHITE x RESET
#define CGREEN(x)	GREEN x RESET

class Wordle
{
	public :

		Wordle(const std::string& words_file);
		~Wordle();

		void initGame();
		void gameHandler();
		void display_dict();
		void display_board();
		void presentation()	const;
		std::string designRow(std::string::iterator it, std::string::iterator it2, std::string &buff_line) const;

	private :

		Wordle();

		std::vector<std::string> 	dict;
		std::vector<std::string> 	board;
		std::string					secret_word;
};

#endif