/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:42:16 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/12 21:44:45 by ahmaidi          ###   ########.fr       */
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

int	here_doc(t_arguments arg)
{
	char	*line;
	int		p[2];

	error(pipe(p), 0);
	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!ft_strncmp(line, arg.argv[2], ft_strlen(arg.argv[2]) - 1))
			break ;
		write(p[1], line, ft_strlen(line));
		free(line);
	}
	close(p[1]);
	return (p[0]);
}
