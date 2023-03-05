/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:27:43 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/05 21:29:01 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	to_left(t_vars *vars)
{
	vars->enn = vars->enn_4;
	if (vars->map[vars->ennemy->x][vars->ennemy->y - 1] != '1'
		&& vars->map[vars->ennemy->x][vars->ennemy->y - 1] != 'C'
		&& vars->map[vars->ennemy->x][vars->ennemy->y - 1] != 'E'
		&& vars->map[vars->ennemy->x][vars->ennemy->y - 1] != 'N')
	{
		vars->map[vars->ennemy->x][vars->ennemy->y] = '0';
		vars->ennemy->y--;
		vars->map[vars->ennemy->x][vars->ennemy->y] = 'N';
		if (vars->map[vars->ennemy->x][vars->ennemy->y] ==
			vars->map[vars->x_of_p][vars->y_of_p])
		{
			ft_free_split(&vars->map);
			free_list_enn(&vars->ennemy);
			destroy_img(vars, 1);
			mlx_destroy_window(vars->mlx, vars->win);
			ft_printf("Game Over\n");
			exit(0);
		}
	}
}

void	to_right(t_vars *vars)
{
	vars->enn = vars->enn_3;
	if (vars->map[vars->ennemy->x][vars->ennemy->y + 1] != '1'
		&& vars->map[vars->ennemy->x][vars->ennemy->y + 1] != 'C'
		&& vars->map[vars->ennemy->x][vars->ennemy->y + 1] != 'E'
		&& vars->map[vars->ennemy->x][vars->ennemy->y + 1] != 'N')
	{
		vars->map[vars->ennemy->x][vars->ennemy->y] = '0';
		vars->ennemy->y++;
		vars->map[vars->ennemy->x][vars->ennemy->y] = 'N';
		if (vars->map[vars->ennemy->x][vars->ennemy->y] ==
			vars->map[vars->x_of_p][vars->y_of_p])
		{
			ft_free_split(&vars->map);
			free_list_enn(&vars->ennemy);
			destroy_img(vars, 1);
			mlx_destroy_window(vars->mlx, vars->win);
			ft_printf("Game Over\n");
			exit(0);
		}
	}
}

void	to_top(t_vars *vars)
{
	vars->enn = vars->enn_1;
	if (vars->map[vars->ennemy->x - 1][vars->ennemy->y] != '1'
		&& vars->map[vars->ennemy->x - 1][vars->ennemy->y] != 'C'
		&& vars->map[vars->ennemy->x - 1][vars->ennemy->y] != 'E'
		&& vars->map[vars->ennemy->x - 1][vars->ennemy->y] != 'N')
	{
		vars->map[vars->ennemy->x][vars->ennemy->y] = '0';
		vars->ennemy->x--;
		vars->map[vars->ennemy->x][vars->ennemy->y] = 'N';
		if (vars->map[vars->ennemy->x][vars->ennemy->y] ==
			vars->map[vars->x_of_p][vars->y_of_p])
		{
			ft_free_split(&vars->map);
			free_list_enn(&vars->ennemy);
			destroy_img(vars, 1);
			mlx_destroy_window(vars->mlx, vars->win);
			ft_printf("Game Over\n");
			exit(0);
		}
	}
}

void	to_bottom(t_vars *vars)
{
	vars->enn = vars->enn_2;
	if (vars->map[vars->ennemy->x + 1][vars->ennemy->y] != '1'
		&& vars->map[vars->ennemy->x + 1][vars->ennemy->y] != 'C'
		&& vars->map[vars->ennemy->x + 1][vars->ennemy->y] != 'E'
		&& vars->map[vars->ennemy->x + 1][vars->ennemy->y] != 'N')
	{
		vars->map[vars->ennemy->x][vars->ennemy->y] = '0';
		vars->ennemy->x++;
		vars->map[vars->ennemy->x][vars->ennemy->y] = 'N';
		if (vars->map[vars->ennemy->x][vars->ennemy->y] ==
			vars->map[vars->x_of_p][vars->y_of_p])
		{
			ft_free_split(&vars->map);
			free_list_enn(&vars->ennemy);
			destroy_img(vars, 1);
			mlx_destroy_window(vars->mlx, vars->win);
			ft_printf("Game Over\n");
			exit(0);
		}
	}
}

int	ennemy(t_vars *vars)
{
	int	rand_num;

	srand(clock());
	rand_num = rand();
	if (rand_num % 4 == 0)
		to_left(vars);
	if (rand_num % 4 == 1)
		to_right(vars);
	if (rand_num % 4 == 2)
		to_top(vars);
	if (rand_num % 4 == 3)
		to_bottom(vars);
	return (0);
}
