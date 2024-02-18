/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:15:24 by fnikzad           #+#    #+#             */
/*   Updated: 2023/12/13 13:20:21 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&((char *)s)[i]);
		i++;
	}
	if (c == 0)
		return ((&((char *)s)[i]));
	return (NULL);
}

size_t	ft_strlen(const char *s1)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1 && s1[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize == 0)
		return (slen);
	if (dstsize <= dlen)
		slen += dstsize;
	else
		slen += dlen;
	while (src[i] != 0 && dlen + 1 < dstsize)
	{
		dst[dlen++] = src[i++];
	}
	dst[dlen] = 0;
	return (slen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s3;

	i = 0;
	if (s1)
		i += ft_strlen(s1);
	if (s2)
		i += ft_strlen(s2);
	i++;
	s3 = malloc (sizeof(char) * i);
	if (!s3 || (!s1 && !s2))
		return (NULL);
	s3[0] = '\0';
	if (s1 && s1[0] != 0)
		ft_strlcat(s3, s1, i);
	if (s2 && s2[0] != 0)
		ft_strlcat(s3, s2, i);
	if (s1)
		free ((char *)s1);
	return (s3);
}
