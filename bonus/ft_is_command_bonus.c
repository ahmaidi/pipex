/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_command_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:54:45 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/10 19:54:47 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_command(char *str, char **envp)
{
	char	**path;
	char	*temp;
	int		correct;

	correct = 0;
	path = ft_split(str, ' ');
	temp = ft_check_cmd(path[0], envp, 1);
	if (temp)
		correct = 1;
	free(temp);
	free_it(path);
	return (correct);
}
