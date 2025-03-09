CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = error_handling.c ft_split.c ft_strjoin.c helper_functions.c pipex.c helper_functions2.c helper_functions3.c helper_functions4.c error_handling2.c
OBJ = $(SRC:.c=.o)
NAME = pipex

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC)  $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean