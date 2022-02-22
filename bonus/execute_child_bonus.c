/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:53:31 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/12 20:15:44 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute_child(char *str, char **envp)
{
	char	**path;
	char	*temp;

	if (ft_strlen(str) != 0)
	{
		path = ft_split(str, ' ');
		temp = ft_check_cmd(path[0], envp, 0);
		if (temp)
		{
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
