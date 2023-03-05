/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:24:45 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/05 21:29:21 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_it(t_vars *vars)
{
	destroy_img(vars, 0);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_free_split(&vars->map);
	ft_printf("Closed\n");
	exit(0);
	return (0);
}

int	annimation(t_vars *vars)
{
	int	i;

	mlx_clear_window(vars->mlx, vars->win);
	put_images(vars->map, vars, -1, -1);
	i = 0;
	vars->coll_1 = mlx_xpm_file_to_image(vars->mlx, "images/c-6-1.xpm", &i, &i);
	return (0);
}

void	get_pos_of_p(char **map, t_vars *vars, int *c)
{
	int	x;
	int	y;

	x = 0;
	vars->map = map;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				(*c)++;
			if (map[x][y] == 'P')
			{
				vars->x_of_p = x;
				vars->y_of_p = y;
			}
			y++;
		}
		x++;
	}
}

void	game(char **map)
{
	t_vars	vars;
	int		col;
	int		lines;
	int		c;

	c = 0;
	vars.count_move = 0;
	get_pos_of_p(map, &vars, &c);
	vars.c = c;
	count_lines_col(&col, &lines, map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, col * 60, lines * 60, "My Game");
	set_images(&vars, 0, 0);
	put_images(map, &vars, -1, -1);
	mlx_loop_hook (vars.mlx, annimation, &vars);
	mlx_hook(vars.win, 17, 0, close_it, &vars);
	mlx_hook(vars.win, 2, 0, move, &vars);
	mlx_loop(vars.mlx);
	ft_free_split(&map);
}
