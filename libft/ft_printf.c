/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:32:37 by fnikzad           #+#    #+#             */
/*   Updated: 2023/10/31 16:25:44 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_if_str(const char *s, int *i)
{
	if (!s)
	{
		if (ft_if_str("(null)", i) == -1)
			return (-1);
	}
	else
	{
		while (*s)
		{
			if (write (1, &(*s), 1) == -1)
				return (-1);
			(*i)++;
			s++;
		}
	}
	return (1);
}

int	ft_if_percent(int *i)
{
	if (ft_putchar('%', i) == -1)
		return (-1);
	return (1);
}

int	ft_next_p(const char *input, va_list args, int *i, int j)
{
	if (input[j] == 's')
		return (ft_if_str(va_arg(args, char *), i));
	if (input[j] == 'd' || input[j] == 'i')
		return (ft_if_d(va_arg(args, int), i));
	if (input[j] == 'x')
		return (ft_if_x(va_arg(args, size_t), i));
	if (input[j] == 'c')
		return (ft_putchar(va_arg(args, int), i));
	if (input[j] == 'p')
		return (ft_if_ptr((unsigned long int)va_arg(args, void *), i));
	if (input[j] == 'X')
		return (ft_if_bigx(va_arg(args, size_t), i));
	if (input[j] == '%')
		return (ft_if_percent(i));
	if (input[j] == 'u')
		return (ft_if_u(va_arg(args, unsigned int), i));
	return (-1);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, input);
	while (input[j])
	{
		if (input[j] == '%')
		{
			if (ft_next_p(input, args, &i, ++j) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(input[j], &i) == -1)
				return (-1);
		}
		j++;
	}
	va_end(args);
	return (i);
}

// int main()
// {
// 	// i = printf("hi\n");
// 	// printf("i: %i\n", i);
// 	char *s = "asdfdfgjdjsdjrhercdgfg";
// 	// ft_printf("hi 42! s: %s, d: %i, x: %X, c: %c, p: %p,
// u: %u\n", NULL, 42, 42, 'a', s, 42);
// 	// printf("hi 42! s: %s, d: %i, x: %X, c: %c,
//  p: %p, u: %u\n", NULL, 42, 42, 'a', s, 42);
// 	int x = ft_printf("0x%p-", (void *)ULONG_MAX);
// 	int y = printf("0x%p-", (void *)ULONG_MAX);
// 	printf("\n%i == %i\n", x, y);
// 	// int *p;
// 	// int result;

// 	// result = ft_printf("%p",p);
// 	// ft_printf("\n%d\n",result);
// 	// result = printf("%p",p);
// 	// printf("\n%d\n",result);

// }
