/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:37:20 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/12 19:22:15 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_child2(char *arg, char *str, int *p, char **envp)
{
	char	**path;
	char	*temp;
	int		fd;

	fd = ft_open_file(arg, "outfile");
	if (fd > 0 && ft_strlen(str) > 0)
	{
		path = ft_split(str, ' ');
		temp = ft_check_cmd(path[0], envp);
		if (temp)
		{
			close(p[1]);
			dup2(p[0], STDIN_FILENO);
			dup2(fd, STDOUT_FILENO);
			close(p[0]);
			close(fd);
			if (execve(temp, path, envp) < 0)
				ft_putstr_fd(strerror(errno), 2);
		}
		free(temp);
		free_it(path);
	}
	else
		ft_putstr_fd(ft_strjoin(str, " :command not found\n"), 2);
	exit(1);
}
