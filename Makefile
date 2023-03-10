# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humartin <humartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 11:51:50 by humartin          #+#    #+#              #
#    Updated: 2023/03/07 12:21:08 by humartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Werror -Wextra
LIB := -lreadline

SRC_DIR := srcs
OBJ_DIR := obj
BIN_DIR := .

NAME := $(BIN_DIR)/push_swap

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NONE := '\033[0m'
GREEN := '\033[92m'
GRAY := '\033[90m'
RED := '\033[91m'
CURSIVE := '\033[3m'

all : $(NAME)

$(NAME): $(OBJ) | $(BIN_DIR)
	@echo $(CURSIVE)$(GRAY)" -- Making $(NAME) --"$(NONE)
	$(CC) $(CFLAGS) $(LIB) $^ -o $@
	@echo "$(NAME): $(GREEN)$(NAME) was created !$(NONE)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
		@echo $(CURSIVE)$(GRAY)" -- Deleting objects --"$(NONE)
		rm -rf $(NAME) $(OBJ)
		@echo "$(RED) objects was deleted !$(NONE)"

fclean:
		@echo $(CURSIVE)$(GRAY)" -- Deleting $(NAME) --"$(NONE)
		rm -rf $(NAME) $(OBJ)
		rm -rf $(NAME) $(OBJ_DIR)
		@echo "$(RED) $(NAME) was deleted !"$(NONE)

re: fclean all
