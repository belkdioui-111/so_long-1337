/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_and_print_images.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:30:16 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/05 21:27:18 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(char **map, t_vars *vars, int i, int j)
{
	int		(*img)(void *, void *, void *, int, int);

	img = mlx_put_image_to_window;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				img (vars->mlx, vars->win, vars->character,
					(vars->y_of_p) * 60, (vars->x_of_p) * 60);
			else if (map[i][j] == '1')
				img (vars->mlx, vars->win, vars->wall, j * 60, i * 60);
			else if (map[i][j] == 'E' && vars->c != 0)
				img (vars->mlx, vars->win, vars->door_c, j * 60, i * 60);
			else if (map[i][j] == 'E' && !(vars->c))
				img (vars->mlx, vars->win, vars->door_o, j * 60, i * 60);
			else if (map[i][j] == 'C')
				img (vars->mlx, vars->win, vars->coll, j * 60, i * 60);
			else if (map[i][j] == 'N' && vars->n != 0)
				img (vars->mlx, vars->win, vars->enn, j * 60, i * 60);
		}
	}
}

void	part_bonus(t_vars *vars, int i)
{
	void	*(*xpm)(void *, char *, int *, int *);

	xpm = mlx_xpm_file_to_image;
	vars->enn = xpm(vars->mlx, "images/e_1.xpm", &i, &i);
	vars->enn_1 = xpm(vars->mlx, "images/e_1.xpm", &i, &i);
	vars->enn_2 = xpm(vars->mlx, "images/e_2.xpm", &i, &i);
	vars->enn_3 = xpm(vars->mlx, "images/e_3.xpm", &i, &i);
	vars->enn_4 = xpm(vars->mlx, "images/e_4.xpm", &i, &i);
	vars->coll_1 = xpm(vars->mlx, "images/c-1-1.xpm", &i, &i);
	vars->coll_2 = xpm(vars->mlx, "images/c-2-1.xpm", &i, &i);
	vars->coll_3 = xpm(vars->mlx, "images/c-3-1.xpm", &i, &i);
	vars->coll_4 = xpm(vars->mlx, "images/c-4-1.xpm", &i, &i);
	vars->coll_5 = xpm(vars->mlx, "images/c-5-1.xpm", &i, &i);
	vars->coll_6 = xpm(vars->mlx, "images/c-6-1.xpm", &i, &i);
	if (!vars->enn || !vars->enn_1 || !vars->enn_2 || !vars->enn_3
		|| !vars->enn_4 || !vars->coll_1 || !vars->coll_2 || !vars->coll_4
		|| !vars->coll_5 || !vars->coll_6)
	{
		ft_printf("Error\n");
		write(2, "you have error in your photos", 30);
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_split(&vars->map);
		free_list_enn(&vars->ennemy);
		exit(2);
	}
}

void	set_images(t_vars *vars, int i, int bonus)
{
	void	*(*xpm)(void *, char *, int *, int *);

	xpm = mlx_xpm_file_to_image;
	vars->coll = xpm(vars->mlx, "images/c-6-1.xpm", &i, &i);
	vars->character = xpm(vars->mlx, "images/char-1.xpm", &i, &i);
	vars->character_1 = xpm(vars->mlx, "images/char-1.xpm", &i, &i);
	vars->character_2 = xpm(vars->mlx, "images/char-2.xpm", &i, &i);
	vars->character_3 = xpm(vars->mlx, "images/char-3.xpm", &i, &i);
	vars->character_4 = xpm(vars->mlx, "images/char-4.xpm", &i, &i);
	vars->door_c = xpm(vars->mlx, "images/door-c.xpm", &i, &i);
	vars->door_o = xpm(vars->mlx, "images/door-o.xpm", &i, &i);
	vars->wall = xpm(vars->mlx, "images/wall-1.xpm", &i, &i);
	if (!vars->coll || !vars->character || !vars->character_1
		|| !vars->character_2 || !vars->character_3 || !vars->character_4
		|| !vars->door_c || !vars->door_o || !vars->wall)
	{
		ft_printf("Error\n");
		write(2, "you have error in your photos", 30);
		mlx_destroy_window(vars->mlx, vars->win);
		ft_free_split(&vars->map);
		exit(2);
	}
	if (bonus == 1)
		part_bonus(vars, i);
}
