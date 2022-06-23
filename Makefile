# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 23:44:29 by rfelipe-          #+#    #+#              #
#    Updated: 2022/06/22 23:11:45 by rfelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
FLAGS = -g -Wall -Wextra -Werror
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck --suppressions=readline.supp -q ./minishell

LIBFT_DIR = ./libft
LIBFT = libft/libft.a

INCLUDE_DIR = ./includes
INCLUDE = $(INCLUDE_DIR)/minishell.h

OBJ_DIR = ./objs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_DIR = ./src
SRC = $(SRC_DIR)/minishell.c \
	$(SRC_DIR)/builtins/echo_prompt.c \
	$(SRC_DIR)/builtins/env_prompt.c \
	$(SRC_DIR)/builtins/execute_builtin.c \
	$(SRC_DIR)/builtins/exit_prompt.c \
	$(SRC_DIR)/builtins/export_prompt.c \
	$(SRC_DIR)/builtins/is_builtin.c \
	$(SRC_DIR)/builtins/pwd_prompt.c \
	$(SRC_DIR)/builtins/unset_prompt.c \
	$(SRC_DIR)/system/keep_prompt.c \
	$(SRC_DIR)/system/set_obj_data.c \
	$(SRC_DIR)/system/start_msg.c \
	$(SRC_DIR)/tokenizer/clean_quotes.c \
	$(SRC_DIR)/tokenizer/redirect_args.c \
	$(SRC_DIR)/tokenizer/replace_env_var.c \
	$(SRC_DIR)/tokenizer/split_args.c \
	$(SRC_DIR)/tokenizer/tokenizer.c \
	$(SRC_DIR)/utils/clean_redirect_input.c \
	$(SRC_DIR)/utils/execute_cmd.c \
	$(SRC_DIR)/utils/fd_utils.c \
	$(SRC_DIR)/utils/redirect.c \
	$(SRC_DIR)/utils/signals.c

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME) -lreadline
	@echo "Minishell compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/builtins
	@mkdir -p $(OBJ_DIR)/system
	@mkdir -p $(OBJ_DIR)/tokenizer
	@mkdir -p $(OBJ_DIR)/utils
	@$(CC) -c $(FLAGS) -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	@echo "Compiling project...\n"
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Deleting EVERYTHING...\n"
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)
	@rm -rf $(CHECKER)
	@echo "Project cleaned up!"

re: fclean all

valgrind: all
	@$(VALGRIND)

v: valgrind
