/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:56:41 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/12 22:04:22 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include <errno.h>
# include <string.h>

# define ERROR "you should execute like this : ./pipex file1 cmd1 cmd2 ...file2"
# define BUFFER_SIZE 100

typedef struct s_arguments
{
	char	**argv;
	char	**envp;
	int		cmd;
	int		is_here_doc;
	int		first_child;
}	t_arguments;

void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_check_cmd(char *cmd, char **envp, int i);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_open_file(char *arg, int i);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	execute_child(char *str, char **envp);
char	*free_it(char **tab);
int		ft_strchr(const char *s, int c);
int		is_command(char *str, char **envp);
void	execute_pipes(int *fd, t_arguments arg);
int		ft_strcmp(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char **s1, char *s2);
int		here_doc(t_arguments arg);
void	child(int *fd, int *p, int i, t_arguments arg);

#endif