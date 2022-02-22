/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:41:44 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/14 18:44:21 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_it(int a, int b)
{
	close(a);
	close(b);
}

static void	error(int p)
{
	if (p == -1)
		perror("pipe ");
}

int	main(int argc, char *argv[], char **envp)
{
	int	end[2];
	int	status;
	int	id1;
	int	id2;

	if (argc == 5)
	{
		error(pipe(end));
		id1 = fork();
		if (id1 < 0)
			perror("Fork ");
		if (id1 == 0)
			execute_child1(argv[1], argv[2], end, envp);
		id2 = fork();
		if (id2 < 0)
			perror("Fork ");
		if (id2 == 0)
			execute_child2(argv[4], argv[3], end, envp);
		close_it(end[0], end[1]);
		waitpid(id1, &status, 0);
		waitpid(id2, &status, 0);
	}
	else
		ft_putstr_fd(ERROR, 2);
	return (0);
}
