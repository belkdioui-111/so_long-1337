/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:13:58 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/05 21:19:25 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_of_c_e(char **new_arr)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (new_arr[i])
	{
		j = 0;
		while (new_arr[i][j])
		{
			if (new_arr[i][j] == 'C' || new_arr[i][j] == 'E')
			{
				n = 1;
				return (n);
			}		
			j++;
		}
		i++;
	}
	return (0);
}

int	fill_all_by_f(int x, int y, char **array, int arr[2])
{
	if (x > 0 && x < arr[0] && y > 0 && y < arr[1]
		&& array[x][y] != '1' && array[x][y] != 'F')
	{
		array[x][y] = 'F';
		if (fill_all_by_f(x - 1, y, array, arr))
			return (1);
		if (fill_all_by_f(x, y - 1, array, arr))
			return (1);
		if (fill_all_by_f(x, y + 1, array, arr))
			return (1);
		if (fill_all_by_f(x + 1, y, array, arr))
			return (1);
	}
	return (0);
}

void	search_of_p(char **arr, int *x, int *y)
{
	*x = 0;
	while (arr[*x])
	{
		*y = 0;
		while (arr[*x][*y])
		{
			if (arr[*x][*y] == 'P')
			{
				return ;
			}
			(*y)++;
		}	
		(*x)++;
	}
}

int	valid_path(char *str, int lines, int col)
{
	char	**new_arr;
	int		pos[2];
	int		arr[2];
	int		i;

	arr[0] = lines;
	arr[1] = col;
	new_arr = ft_split(str, '\n');
	free(str);
	search_of_p(new_arr, &pos[0], &pos[1]);
	fill_all_by_f(pos[0], pos[1], new_arr, arr);
	i = search_of_c_e(new_arr);
	ft_free_split(&new_arr);
	if (i)
	{
		ft_printf("invalide path");
		return (0);
	}
	return (1);
}
