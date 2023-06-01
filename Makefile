# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 17:00:30 by marvin            #+#    #+#              #
#    Updated: 2023/06/01 14:37:25 by mzarichn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

#FT_PRINTF = ./Library/Printf/libftprintf.a
#FT_PRINTF_PATH = ./Library/Printf

INC = -I ./Library -I ./Library/Libft  #-fsanitize=address

SRC_PATH = ./src

OBJ_PATH = ./objects

SRC_NAME = push_swap.c checker.c\

OBJS = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

DEFAULT = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m


all: $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(INC) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled $(DEFAULT)"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p objects
	@$(CC) -c $(CFLAGS) $(Library) $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -rf objects/
	@echo "$(YELLOW)$(NAME).o files are removed$(DEFAULT)"

fclean:
	@rm -rf objects/
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) is deleted$(DEFAULT)"


re: fclean all