NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I includes

SRC_DIR = src
SRC = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/routine.c \
		$(SRC_DIR)/actions.c \
		$(SRC_DIR)/monitor.c \
		$(SRC_DIR)/utils.c 

DEPS = includes/philo.h

OBJ = $(SRC:.c=.o)
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re: fclean all

test: re
	./$(NAME) 5 800 200 200 7