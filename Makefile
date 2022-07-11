NAME    = computorv1

CC      = clang++
CFLAGS  = -Wall -Werror -Wextra

SRCS    =	main.cpp \
			utils.cpp \
			classes/data.cpp \
			classes/equation.cpp


OBJS    = $(SRCS:.cpp=.o)

all:    $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY:         all clean fclean re