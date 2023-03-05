/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:28:45 by bel-kdio          #+#    #+#             */
/*   Updated: 2022/10/26 11:30:10 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hexa(long long unsigned int n, int *count, char *base)
{
	if (n >= 0 && n < 16)
		*count += ft_printf_putchar(base[n]);
	else
	{
		ft_printf_hexa (n / 16, count, base);
		ft_printf_hexa (n % 16, count, base);
	}
}

void	ft_printf_hexaa(unsigned int n, int *count, char *base)
{
	if (n >= 0 && n < 16)
		*count += ft_printf_putchar(base[n]);
	else
	{
		ft_printf_hexaa (n / 16, count, base);
		ft_printf_hexaa (n % 16, count, base);
	}
}

void	ft_printf_zhex(long long unsigned n, int *count, char *base)
{
	write(1, "0x", 2);
	*count += 2;
	if (n < 16)
		*count += ft_printf_putchar(base[n]);
	else
	{
		ft_printf_hexa (n / 16, count, base);
		ft_printf_hexa (n % 16, count, base);
	}
}
