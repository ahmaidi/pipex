/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:41:30 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/12 15:20:22 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include <errno.h>
# include <string.h>

# define ERROR "you should execute like this : ./pipex file1 cmd1 cmd2 file2"

void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_check_cmd(char *cmd, char **envp);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_open_file(char *str, char *modde);
void	ft_putchar_fd(char c, int fd);
void	execute_child1(char *arg, char *str, int *p, char **envp);
void	execute_child2(char *arg, char *str, int *p, char **envp);
char	*free_it(char **tab);
void	ft_putstr_fd(char *s, int fd);
int		ft_strchr(const char *s, int c);

#endif