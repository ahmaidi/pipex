/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:24:41 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/01/04 13:19:32 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_file(char *str, char *mode)
{
	int	fd;

	fd = -1;
	if (!ft_strncmp(mode, "infile", 6))
	{
		if (!access(str, F_OK) && !access(str, R_OK))
		{
			fd = open(str, O_RDONLY);
			return (fd);
		}
	}
	else
	{
		fd = open(str, O_CREAT | O_RDWR | O_TRUNC, 0644);
		return (fd);
	}
	perror(str);
	return (fd);
}
