/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:27:49 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/05 21:24:48 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_left_b(t_vars *vars)
{
	vars->character = vars->character_4;
	if (vars->map[vars->x_of_p][vars->y_of_p - 1] != '1')
	{
		vars->count_move++;
		ft_printf("%d\n", vars->count_move);
		vars->y_of_p--;
	}
	if (vars->map[vars->x_of_p][vars->y_of_p] == 'C')
	{
		vars->map[vars->x_of_p][vars->y_of_p] = '0';
		vars->c--;
	}
	if ((vars->map[vars->x_of_p][vars->y_of_p] == 'E' && vars->c == 0) ||
		vars->map[vars->x_of_p][vars->y_of_p] == 'N')
	{
		destroy_img(vars, 1);
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_split(&vars->map);
		free_list_enn(&vars->ennemy);
		ft_printf("FINISH");
		exit(0);
	}
}

void	to_right_b(t_vars *vars)
{
	vars->character = vars->character_3;
	if (vars->map[vars->x_of_p][vars->y_of_p + 1] != '1')
	{
		vars->count_move++;
		ft_printf("%d\n", vars->count_move);
		vars->y_of_p++;
	}
	if (vars->map[vars->x_of_p][vars->y_of_p] == 'C')
	{
		vars->map[vars->x_of_p][vars->y_of_p] = '0';
		vars->c--;
	}
	if ((vars->map[vars->x_of_p][vars->y_of_p] == 'E' && vars->c == 0) ||
		vars->map[vars->x_of_p][vars->y_of_p] == 'N')
	{
		destroy_img(vars, 1);
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_split(&vars->map);
		free_list_enn(&vars->ennemy);
		ft_printf("FINISH");
		exit(0);
	}
}

void	to_top_b(t_vars *vars)
{
	vars->character = vars->character_2;
	if (vars->map[vars->x_of_p - 1][vars->y_of_p] != '1')
	{
		vars->count_move++;
		ft_printf("%d\n", vars->count_move);
		vars->x_of_p--;
	}
	if (vars->map[vars->x_of_p][vars->y_of_p] == 'C')
	{
		vars->map[vars->x_of_p][vars->y_of_p] = '0';
		vars->c--;
	}
	if ((vars->map[vars->x_of_p][vars->y_of_p] == 'E' && vars->c == 0) ||
		vars->map[vars->x_of_p][vars->y_of_p] == 'N')
	{
		destroy_img(vars, 1);
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_split(&vars->map);
		free_list_enn(&vars->ennemy);
		ft_printf("FINISH");
		exit(0);
	}
}

void	to_bottom_b(t_vars *vars)
{
	vars->character = vars->character_1;
	if (vars->map[vars->x_of_p + 1][vars->y_of_p] != '1')
	{
		vars->count_move++;
		ft_printf("%d\n", vars->count_move);
		vars->x_of_p++;
	}
	if (vars->map[vars->x_of_p][vars->y_of_p] == 'C')
	{
		vars->map[vars->x_of_p][vars->y_of_p] = '0';
		vars->c--;
	}
	if ((vars->map[vars->x_of_p][vars->y_of_p] == 'E' && vars->c == 0) ||
		vars->map[vars->x_of_p][vars->y_of_p] == 'N')
	{
		destroy_img(vars, 1);
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_split(&vars->map);
		free_list_enn(&vars->ennemy);
		ft_printf("FINISH");
		exit(0);
	}
}

int	move_b(int keycode, t_vars *vars)
{
	if (keycode == 123 || keycode == 0)
		to_left_b(vars);
	else if (keycode == 124 || keycode == 2)
		to_right_b(vars);
	else if (keycode == 126 || keycode == 13)
		to_top_b(vars);
	else if (keycode == 125 || keycode == 1)
		to_bottom_b(vars);
	else if (keycode == 53)
	{
		destroy_img(vars, 1);
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_split(&vars->map);
		free_list_enn(&vars->ennemy);
		ft_printf("Closed");
		exit(0);
	}
	return (0);
}
