/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:39:39 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/12 22:04:09 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child(int *fd, int *p, int i, t_arguments arg)
{
	if (fd[0] >= 0)
		dup2(fd[0], 0);
	else
		dup2(p[0], 0);
	if (is_command(arg.argv[i + arg.is_here_doc + 2], arg.envp))
	{
		if (i != arg.cmd - 1)
			dup2(p[1], 1);
		else
			dup2(fd[1], 1);
	}
	close(fd[0]);
	close(p[1]);
	execute_child(arg.argv[i + arg.is_here_doc + 2], arg.envp);
}
