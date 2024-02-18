/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:11:39 by fnikzad           #+#    #+#             */
/*   Updated: 2023/10/14 15:35:20 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i] != 0)
	{
		write (fd, &s[i], 1);
		i++;
	}
}

// int main()
// {
// 	ft_putstr_fd(NULL, 2);
// }