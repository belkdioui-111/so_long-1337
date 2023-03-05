/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:22:06 by bel-kdio          #+#    #+#             */
/*   Updated: 2022/10/26 12:39:57 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conditions(va_list args, const char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_printf_putchar(va_arg(args, int));
	else if (s == 's')
		count += ft_printf_putstr(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		ft_printf_putnbr(va_arg(args, int), &count);
	else if (s == '%')
		count += ft_printf_putchar('%');
	else if (s == 'u')
		ft_printf_u(va_arg(args, unsigned int), &count);
	else if (s == 'x')
		ft_printf_hexa(va_arg(args, unsigned int), &count,
			"0123456789abcdef");
	else if (s == 'X')
		ft_printf_hexaa(va_arg(args, unsigned int), &count,
			"0123456789ABCDEF");
	else if (s == 'p')
		ft_printf_zhex(va_arg(args, long long unsigned), &count,
			"0123456789abcdef");
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			count += conditions(args, *s);
		}
		else
			count += ft_printf_putchar(*s);
		s++;
	}
	va_end(args);
	return (count);
}
