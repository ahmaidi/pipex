/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:56:35 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/14 18:49:42 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static t_arguments	fill_it(char **ar1, char **ar2, int n, int bool)
{
	t_arguments	arg;

	arg.argv = ar1;
	arg.envp = ar2;
	arg.cmd = n;
	arg.is_here_doc = bool;
	arg.first_child = 0;
	return (arg);
}

int	main(int argc, char *argv[], char **envp)
{
	int			fd[2];
	int			cmd;
	t_arguments	arg;

	if (argc >= 5)
	{
		if (ft_strcmp(argv[1], "here_doc") != 0)
		{
			fd[0] = ft_open_file(argv[1], 1);
			fd[1] = ft_open_file(argv[argc - 1], 0);
			cmd = argc - 3;
			arg = fill_it(argv, envp, cmd, 0);
			execute_pipes(fd, arg);
		}
		else
		{
			fd[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
			cmd = argc - 4;
			arg = fill_it(argv, envp, cmd, 1);
			execute_pipes(fd, arg);
		}
	}
	else
		ft_putstr_fd(ERROR, 2);
	return (0);
}
