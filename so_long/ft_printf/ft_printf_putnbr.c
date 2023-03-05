/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:55:50 by bel-kdio          #+#    #+#             */
/*   Updated: 2022/10/26 11:49:06 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_printf_putnbr(int n, int *count)
{
	if (n <= 9 && n >= 0)
	{
		ft_printf_putchar(n + '0');
		*count += 1;
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else if (n < 0)
	{
		ft_printf_putchar('-');
		*count += 1;
		n = n * (-1);
		ft_printf_putnbr(n, count);
	}
	else
	{
		ft_printf_putnbr(n / 10, count);
		ft_printf_putnbr((n % 10), count);
	}
}
