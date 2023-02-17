# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suhovhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 13:59:48 by suhovhan          #+#    #+#              #
#    Updated: 2022/04/21 13:59:53 by suhovhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = ../obj
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[0;33m
NEW=\033[0;36m
END=\033[0m

RM = rm -f

AR = ar rsc

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)CREATED $(END)✅ $(YELLOW)$@$(END)"

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(NEW)LIBFT $(END)$(GREEN)IS READY$(END) 🆒"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
