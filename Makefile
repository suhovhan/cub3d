NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes #-fsanitize=address -g

OBJ_DIR = obj
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

MK = mkdir -p
RF = rm -f
RMRF = rm -rf

LIBCACH = ~/Library/Caches/

$(OBJ_DIR)/%.o: ./src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR):
	@$(MK) $(OBJ_DIR)

clean:
	$(RMRF) $(OBJ_DIR)

fclean: clean
	$(RF)  $(NAME)
	# $(RMRF) $(LIBCACH)

re: fclean all

.PHONY: all clean fclean re
