/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:54:58 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/10 19:55:00 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	error(char *s1, char *s2)
{
	free(s1);
	perror(s2);
}

int	ft_open_file(char *arg, int i)
{
	int		fd;
	char	*mode;

	fd = -1;
	if (i == 1)
		mode = ft_strdup("infile");
	else
		mode = ft_strdup("outfile");
	if (!ft_strncmp(mode, "infile", 6))
	{
		if (!access(arg, F_OK) && !access(arg, R_OK))
		{
			fd = open(arg, O_RDONLY);
			free(mode);
			return (fd);
		}
	}
	else
	{
		fd = open(arg, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		free(mode);
		return (fd);
	}
	error(mode, arg);
	return (fd);
}
