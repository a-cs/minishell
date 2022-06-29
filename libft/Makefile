# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 20:36:30 by rfelipe-          #+#    #+#              #
#    Updated: 2022/06/29 00:36:53 by acarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
FLAGS = -g -Wall -Wextra -Werror

SRC_DIR = ./src
OBJ_DIR = ./objs
INCLUDE_DIR = ./includes
INCLUDES = -I$(INCLUDE_DIR)

SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_chrpos.c \
		ft_chrqty.c \
		ft_free_matrix.c \
		ft_free_ptr.c \
		ft_is_all_blank.c \
		ft_is_all_digit.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_lst_to_matrix.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_matrix_to_str.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strnstr.c \
		ft_strtrim.c \
		ft_substr.c \
		get_next_line_utils.c \
		get_next_line.c

OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))
SRCS := $(addprefix $(SRC_DIR)/,$(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCLUDES) $< -c -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
