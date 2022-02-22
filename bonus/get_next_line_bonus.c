/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:56:12 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/10 19:56:13 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*get_line(char **stock)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while ((*stock)[i] != '\n')
		i++;
	line = ft_substr_gnl(*stock, 0, i + 1);
	tmp = *stock;
	*stock = ft_substr_gnl(*stock, i + 1, ft_strlen(*stock) - i);
	free(tmp);
	return (line);
}

static char	*get_stock(char	**stock)
{
	char	*ligne;

	if (*stock && **stock != '\0')
	{
		ligne = *stock;
		*stock = NULL;
		return (ligne);
	}
	else
	{
		free(*stock);
		*stock = NULL;
		return (NULL);
	}
}

static char	*free_it_gnl(char *buffer, char *stock)
{
	free(buffer);
	free(stock);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	int			read_f;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stock, '\n'))
	{
		read_f = read(fd, buffer, BUFFER_SIZE);
		if (read_f < 0)
			return (free_it_gnl(buffer, stock));
		if (read_f == 0)
			break ;
		buffer[read_f] = 0;
		stock = ft_strjoin_gnl(&stock, buffer);
	}
	free(buffer);
	if (ft_strchr(stock, '\n'))
		return (get_line(&stock));
	return (get_stock(&stock));
}
