NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src 
SRC = main.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

all: fclean all