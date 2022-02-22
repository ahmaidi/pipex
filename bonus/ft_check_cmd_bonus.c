/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:54:30 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/10 19:54:31 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static	char	*effacer_path(char **str)
{
	char	*string;

	string = ft_strdup(*str + 6);
	free(*str);
	return (string);
}

static	char	*existence_cmd(char **pth, char *cmd)
{
	int		i;
	char	*temp;
	char	*pth_cmd;

	i = 0;
	pth_cmd = NULL;
	while (pth[i])
	{
		temp = ft_strjoin(pth[i], "/");
		pth_cmd = ft_strjoin(temp, cmd);
		if (!access(pth_cmd, F_OK) && !access(pth_cmd, X_OK))
		{
			free_it(pth);
			free(temp);
			return (pth_cmd);
		}
		free(temp);
		free(pth_cmd);
		i++;
	}
	free_it(pth);
	return (NULL);
}

static void	path_envp_it(char **str, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
		{
			*str = ft_strdup(envp[i]);
			break ;
		}
		i++;
	}
}

static char	*path_it(char *cmd)
{
	char	*str;

	if (!access(cmd, F_OK) && !access(cmd, X_OK))
			str = ft_strdup(cmd);
	else
	{
		perror(cmd);
		return (NULL);
	}	
	return (str);
}

char	*ft_check_cmd(char *cmd, char **envp, int j)
{
	int		i;
	char	*str;
	char	**path;

	i = 0;
	str = NULL;
	if (ft_strchr(cmd, '/'))
	{
		return (path_it(cmd));
	}
	else
	{
		path_envp_it(&str, envp);
		str = effacer_path(&str);
		i = 0;
		path = ft_split(str, ':');
		free(str);
		str = existence_cmd(path, cmd);
	}
	if (str)
		return (str);
	else if (j != 0)
		ft_putstr_fd(ft_strjoin(cmd, " :command not found\n"), 2);
	return (NULL);
}
