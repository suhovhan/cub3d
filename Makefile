NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Imlx #-fsanitize=address -g
LIBFT = libft
LINKER = ./libft/libft.a
MLX = -lmlx -framework OpenGL -framework Appkit

OBJ_DIR = obj

SRC_PARS = $(wildcard src/parsing/*.c)
OBJ_PARS = $(patsubst src/parsing/%.c, $(OBJ_DIR)/%.o, $(SRC_PARS))

SRC_CAST = $(wildcard src/raycasting/*.c, src/raycasting/*.cpp)
OBJ_CAST = $(patsubst src/raycasting/%.c, $(OBJ_DIR)/%.o, $(SRC_CAST))

SRC_GNL = $(wildcard src/getnextline/*.c)
OBJ_GNL = $(patsubst src/getnextline/%.c, $(OBJ_DIR)/%.o, $(SRC_GNL))

SRC_MAIN = $(wildcard src/*.c)
OBJ_MAIN = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC_MAIN))

MK = mkdir -p
RF = rm -f
RMRF = rm -rf

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;33m
NEW=\033[0;36m
END=\033[0m

LIBCACH = ~/Library/Caches/

$(OBJ_DIR)/%.o: src/parsing/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)CREATED $(END)✅ $(YELLOW)$@$(END)"

$(OBJ_DIR)/%.o: src/raycasting/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)CREATED $(END)✅ $(YELLOW)$@$(END)"

$(OBJ_DIR)/%.o: src/getnextline/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)CREATED $(END)✅ $(YELLOW)$@$(END)"

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)CREATED $(END)✅ $(YELLOW)$@$(END)"

all: $(NAME)

$(NAME): $(OBJ_PARS) $(OBJ_GNL) $(OBJ_MAIN) $(OBJ_CAST)
	@make -C $(LIBFT)
	@$(CC) $(LINKER) $(CFLAGS) $(MLX) -o $(NAME) $(OBJ_PARS) $(OBJ_CAST) $(OBJ_GNL) $(OBJ_MAIN)
	@echo "$(NEW)CUB3D $(END)$(GREEN)IS READY$(END) 🆒"

$(OBJ_DIR):
	@$(MK) $(OBJ_DIR)

clean:
	@$(RMRF) $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RF)  $(NAME)
	@make fclean -C $(LIBFT)
	@#$(RMRF) $(LIBCACH)

re: fclean all

.PHONY: all clean fclean re
