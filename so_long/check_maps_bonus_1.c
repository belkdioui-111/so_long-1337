/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_bonus_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:46:13 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/02/26 08:52:06 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	between_lines(char *line, char last, char first, unsigned int len[2])
{
	if (((len[0] == len[1]) || (len[0] == 1)) && (first != '1' || last != '1'))
		return (0);
	else if ((len[0] < len[1] && len[0] > 1) && (*line != '0') && (*line != 'C')
		&& (*line != 'E') && (*line != 'P') && (*line != '1') && (*line != 'N'))
		return (0);
	return (1);
}

int	check_the_map_b(char *line, int number_of_lines, int max_of_lines)
{
	char			last;
	unsigned int	len[2];
	char			first;

	len[0] = ft_strlen(line) - 1;
	len[1] = ft_strlen(line) - 1;
	last = *(line + (len[0] - 1));
	first = *line;
	while (*line)
	{
		if (number_of_lines == max_of_lines || number_of_lines == 0)
		{
			if (*line != '1' && *line != '\n')
				return (0);
		}
		else if (number_of_lines > 0 && number_of_lines < max_of_lines)
		{
			if (!(between_lines(line, last, first, len)))
				return (0);
		}
		len[0]--;
		line++;
	}
	return (1);
}
