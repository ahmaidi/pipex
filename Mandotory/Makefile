# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 15:45:09 by ahmaidi           #+#    #+#              #
#    Updated: 2022/02/14 17:55:08 by ahmaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc 
SRCS = ft_strlen.c ft_split.c ft_strdup.c ft_strncmp.c ft_calloc.c ft_check_cmd.c ft_strjoin.c \
ft_open_file.c ft_bzero.c execute_child1.c execute_child2.c free_it.c ft_putstr.c ft_strchr.c pipex.c 
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f
all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o pipex
	@echo "\033[92mExecution file Created\033[0m"
fclean:
	$(RM) $(NAME)
	@echo "\033[91mExecution file deleted\033[0m"
re: fclean all

.PHONY: all fclean re