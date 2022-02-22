/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:39:36 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/14 17:51:10 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_str(char *s1, char **s2)
{
	free(s1);
	free_it(s2);
}

static void	close_file(int a, int b)
{
	close(a);
	close(b);
}

void	execute_child1(char *arg, char *str, int *p, char **envp)
{
	char	**path;
	char	*temp;
	int		fd;

	fd = ft_open_file(arg, "infile");
	if (fd < 0)
		exit(1);
	if (ft_strlen(str) != 0)
	{
		path = ft_split(str, ' ');
		temp = ft_check_cmd(path[0], envp);
		if (temp)
		{
			close(p[0]);
			dup2(fd, STDIN_FILENO);
			dup2(p[1], STDOUT_FILENO);
			close_file(fd, p[1]);
			if (execve(temp, path, envp) < 0)
				ft_putstr_fd(strerror(errno), 2);
		}
		free_str(temp, path);
	}
	else
		ft_putstr_fd(ft_strjoin(str, " :command not found\n"), 2);
	exit(1);
}
