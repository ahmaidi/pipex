/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipes_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:53:18 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/12 22:03:55 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	error(int p, int is_pid)
{
	if (p == -1 && is_pid == 0)
		perror("pipe ");
	if (p == -1 && is_pid == 1)
		perror("fork ");
}

static void	wait_it(int nbr_cmd, int *fd)
{
	int	i;

	i = 0;
	while (i < nbr_cmd)
	{
		wait(0);
		i++;
	}
	close(fd[0]);
	close(fd[1]);
}

static void	childs(int *fd, int *p, int i, t_arguments arg)
{
	if (arg.first_child)
		exit(1);
	child(fd, p, i, arg);
}

static void	parent(int *fd, int *p)
{
	close(fd[0]);
	fd[0] = p[0];
	close(p[1]);
}

void	execute_pipes(int *fd, t_arguments arg)
{
	int	i;
	int	p[2];
	int	pid;

	i = 0;
	if (arg.is_here_doc)
		fd[0] = here_doc(arg);
	if (fd[0] < 0)
		arg.first_child = 1;
	while (i < arg.cmd)
	{
		if (i != arg.cmd - 1)
			error(pipe(p), 0);
		error(pid = fork(), 1);
		if (pid == 0)
			childs(fd, p, i, arg);
		else if (pid > 0)
			parent(fd, p);
		i++;
		arg.first_child = 0;
	}
	wait_it(arg.cmd, fd);
}
