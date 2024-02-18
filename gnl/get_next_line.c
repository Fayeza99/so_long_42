/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:13:44 by fnikzad           #+#    #+#             */
/*   Updated: 2023/12/13 15:39:23 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy(char	*str)
{
	int		i;
	char	*next;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	next = malloc (i + 1);
	if (!next)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		next[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		next[i++] = '\n';
	next[i] = '\0';
	return (next);
}

char	*get_the_rest(char	*str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_str = malloc (ft_strlen(str) - i + 1);
	if (!new_str)
		return (NULL);
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free (str);
	return (new_str);
}

void	ft_read(int fd, char **str)
{
	int		i;
	char	next[BUFFER_SIZE + 1];

	i = 1;
	while (i != 0)
	{
		i = read(fd, next, BUFFER_SIZE);
		if (i == -1)
			return ;
		next[i] = '\0';
		*str = ft_strjoin(*str, next);
		if (ft_strchr(*str, '\n') || i == 0)
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*next;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	ft_read(fd, &str);
	if (!str)
		return (free(str), NULL);
	next = ft_copy(str);
	str = get_the_rest(str);
	return (next);
}
