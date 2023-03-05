/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:19:16 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/05 21:29:36 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_it(t_vars *vars)
{
	destroy_img(vars, 1);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_free_split(&vars->map);
	ft_printf("Closed\n");
	exit(0);
	return (0);
}

void	images_annimation(int *cnt, t_vars *vars)
{
	if (*cnt < 30)
		vars->coll = vars->coll_1;
	else if (*cnt < 60)
		vars->coll = vars->coll_2;
	else if (*cnt < 90)
		vars->coll = vars->coll_3;
	else if (*cnt < 120)
		vars->coll = vars->coll_4;
	else if (*cnt < 150)
		vars->coll = vars->coll_5;
	else if (*cnt < 180)
		vars->coll = vars->coll_6;
	else if (*cnt > 210)
		*cnt = 0;
}

int	annimation(t_vars *vars)
{
	static int	cnt;
	char		*moves;

	mlx_clear_window(vars->mlx, vars->win);
	put_images(vars->map, vars, -1, -1);
	moves = ft_itoa(vars->count_move);
	if (cnt % 100 == 0 && vars->n != 0)
	{
		while (vars->ennemy)
		{
			ennemy(vars);
			vars->ennemy = vars->ennemy->next;
		}
		vars->ennemy = vars->save_enn;
	}
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0xcc5315, moves);
	cnt++;
	images_annimation(&cnt, vars);
	return (0);
}

void	get_pos_of_p(char **map, t_vars *vars, int *c)
{
	int	x;
	int	y;

	x = 0;
	vars->n = 0;
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
			if (map[x][y] == 'N')
				vars->n++;
			y++;
		}
		x++;
	}
}

void	game_b(char **map)
{
	t_vars		vars;
	int			col;
	int			lines;
	t_ennemy	*enn;
	int			c;

	c = 0;
	enn = NULL;
	vars.count_move = 0;
	get_pos_of_p(map, &vars, &c);
	get_pos_of_ennemy(map, &enn, -1, -1);
	vars.ennemy = enn;
	vars.save_enn = enn;
	vars.c = c;
	count_lines_col(&col, &lines, map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, col * 60, lines * 60, "My Game");
	set_images(&vars, 0, 1);
	put_images(map, &vars, -1, -1);
	mlx_loop_hook(vars.mlx, annimation, &vars);
	mlx_hook(vars.win, 17, 0, close_it, &vars);
	mlx_hook(vars.win, 2, 0, move_b, &vars);
	mlx_loop(vars.mlx);
}
