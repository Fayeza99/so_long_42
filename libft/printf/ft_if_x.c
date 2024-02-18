/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:11:23 by fnikzad           #+#    #+#             */
/*   Updated: 2023/10/31 15:45:27 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_x(size_t d, int *i)
{
	unsigned int	k;

	k = (unsigned int)d;
	if (k >= 16)
	{
		if (ft_if_x(k / 16, i) == -1)
			return (-1);
		if (ft_if_x(k % 16, i) == -1)
			return (-1);
	}
	else
	{
		if (k <= 9)
		{
			if (ft_putchar(k + '0', i) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(k + 'a' - 10, i) == -1)
				return (-1);
		}
	}
	return (1);
}

int	ft_if_bigx(size_t d, int *i)
{
	unsigned int	k;

	k = (unsigned int)d;
	if (k >= 16)
	{
		if (ft_if_bigx(k / 16, i) == -1)
			return (-1);
		if (ft_if_bigx(k % 16, i) == -1)
			return (-1);
	}
	else
	{
		if (k <= 9)
		{
			if (ft_putchar(k + '0', i) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(k + 'A' - 10, i) == -1)
				return (-1);
		}
	}
	return (1);
}
