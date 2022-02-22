# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 15:45:09 by ahmaidi           #+#    #+#              #
#    Updated: 2022/02/12 22:04:13 by ahmaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc 
SRCS = ft_strlen_bonus.c ft_split_bonus.c ft_strdup_bonus.c ft_strncmp_bonus.c ft_calloc_bonus.c ft_check_cmd_bonus.c ft_strjoin_bonus.c \
ft_open_file_bonus.c ft_bzero_bonus.c execute_child_bonus.c free_it_bonus.c ft_putstr_bonus.c ft_strchr_bonus.c \
pipex_bonus.c ft_is_command_bonus.c execute_pipes_bonus.c ft_strcmp_bonus.c get_next_line_bonus.c \
get_next_line_utils_bonus.c ft_here_doc_bonus.c ft_child_bonus.c
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