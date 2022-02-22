/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:56:19 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/02/10 19:56:23 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin_gnl(char **s1, char *s2)
{
	char			*str_join;
	size_t			len;
	unsigned int	i;

	if (!*s1 && s2)
		return (ft_strdup(s2));
	i = 0;
	len = ft_strlen(*s1) + ft_strlen(s2);
	str_join = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_join)
		return (NULL);
	while ((*s1)[i])
	{
		str_join[i] = (*s1)[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str_join[i + ft_strlen(*s1)] = s2[i];
		i++;
	}
	str_join[i + ft_strlen(*s1)] = '\0';
	free(*s1);
	return (str_join);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	else
	{
		while (i < len && s[i + start])
		{
			substr[i] = s[i + start];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
