/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:17:59 by fnikzad           #+#    #+#             */
/*   Updated: 2023/10/31 15:32:09 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointerprinter(unsigned long int ptr, int *i)
{
	if (ptr >= 16)
	{
		pointerprinter(ptr / 16, i);
		pointerprinter(ptr % 16, i);
	}
	else
	{
		if (ptr <= 9)
		{
			if (ft_putchar(ptr + '0', i) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(ptr + 'a' - 10, i) == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_if_ptr(unsigned long int ptr, int *i)
{
	if (ft_if_str("0x", i) == -1)
		return (-1);
	if (pointerprinter(ptr, i) == -1)
		return (-1);
	return (1);
}
