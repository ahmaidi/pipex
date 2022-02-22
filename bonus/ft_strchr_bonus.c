/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:55:28 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/10 19:55:30 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char)c)
	{
		if (!s)
			return (0);
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				return (1);
			i++;
		}
	}
	return (0);
}
