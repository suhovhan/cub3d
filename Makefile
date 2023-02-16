NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes #-fsanitize=address -g
LIBFT = libft
LINKER = ./libft/libft.a

OBJ_DIR = obj
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

SRC_GNL = $(wildcard getnextline/*.c)
OBJ_GNL = $(patsubst getnextline/%.c, $(OBJ_DIR)/%.o, $(SRC_GNL))

MK = mkdir -p
RF = rm -f
RMRF = rm -rf

LIBCACH = ~/Library/Caches/

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: getnextline/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_GNL)
	make -C $(LIBFT)
	$(CC) $(LINKER) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_GNL)

$(OBJ_DIR):
	@$(MK) $(OBJ_DIR)

clean:
	$(RMRF) $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean: clean
	$(RF)  $(NAME)
	make fclean -C $(LIBFT)
	# $(RMRF) $(LIBCACH)

re: fclean all

.PHONY: all clean fclean re
