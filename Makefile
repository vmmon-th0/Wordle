CLANG		= clang++
NAME		= wordle
SRCS		= main.cpp wordle.cpp
CPPFLAGS	= -Werror -Wall -Wextra -std=c++98
HPP 		= wordle.hpp
OBJS		= $(SRCS:.cpp=.o)

%.o : %.cpp
		$(CLANG) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HPP)
	@echo "\033[0;33mLinking process..."
	$(CLANG) -o $(NAME) $(OBJS)
	@echo "\033[0;32m-----------------------------------"
	@echo "\033[0;32m|              DONE               |"
	@echo "\033[0;32m-----------------------------------"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re