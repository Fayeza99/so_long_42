/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_iud.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:15:22 by fnikzad           #+#    #+#             */
/*   Updated: 2024/01/29 10:54:58 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_d(int d, int *i)
{
	if (d == -2147483648)
	{
		if (ft_if_str("-2147483648", i) == -1)
			return (-1);
		return (1);
	}
	else if (d < 0)
	{
		if (ft_putchar('-', i) == -1)
			return (-1);
		ft_if_d(-d, i);
	}
	else if (d >= 0 && d < 10)
	{
		if (ft_putchar(d + '0', i) == -1)
			return (-1);
	}
	else
	{
		if (ft_if_d(d / 10, i) == -1)
			return (-1);
		if (ft_putchar(d % 10 + '0', i) == -1)
			return (-1);
	}
	return (1);
}

int	ft_if_u(unsigned int d, int *i)
{
	if (d >= 0 && d < 10)
	{
		if (ft_putchar(d + '0', i) == -1)
			return (-1);
	}
	else
	{
		if (ft_if_u(d / 10, i) == -1)
			return (-1);
		if (ft_putchar(d % 10 + '0', i) == -1)
			return (-1);
	}
	return (1);
}
