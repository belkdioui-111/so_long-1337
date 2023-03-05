/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:09:55 by bel-kdio          #+#    #+#             */
/*   Updated: 2022/10/26 11:29:50 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_printf_u(unsigned int n, int *count)
{
	if (n <= 9 && n >= 0)
	{
		ft_printf_putchar(n + '0');
		*count += 1;
	}
	else
	{
		ft_printf_u(n / 10, count);
		ft_printf_u((n % 10), count);
	}
}
