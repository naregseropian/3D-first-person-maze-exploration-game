NAME = cub3D

CFLAGS = -g -Wall -Wextra -Werror -Iinclude/
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

CC = gcc

SRC = $(wildcard src/*.c)
GNL = $(wildcard get_next_line/*.c)

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GNL) $(MLXFLAGS) -o $(NAME)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
