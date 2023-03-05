/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:23:01 by bel-kdio          #+#    #+#             */
/*   Updated: 2022/10/26 11:51:37 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_printf_putchar(int c);
int		ft_printf_putstr(char *s);
void	ft_printf_putnbr(int n, int *count);
void	ft_printf_u(unsigned int n, int *count);
void	ft_printf_hexa(long long unsigned int n, int *count, char *base);
void	ft_printf_hexaa(unsigned int n, int *count, char *base);
void	ft_printf_zhex(long long unsigned n, int *count, char *base);

#endif
