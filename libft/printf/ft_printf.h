/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:02:28 by fnikzad           #+#    #+#             */
/*   Updated: 2024/01/29 10:55:19 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(int c, int *i);
int		ft_if_x(size_t d, int *i);
int		ft_if_d(int d, int *i);
int		ft_if_u(unsigned int d, int *i);
int		ft_if_bigx(size_t d, int *i);
int		ft_if_ptr(unsigned long int ptr, int *i);
int		pointerprinter(unsigned long int ptr, int *i);
int		ft_if_str(const char *s, int *i);
int		ft_if_percent(int *i);
int		ft_printf(const char *input, ...);
int		ft_next_p(const char *input, va_list args, int *i, int j);

#endif