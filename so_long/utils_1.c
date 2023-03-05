/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:08:07 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/04 20:11:53 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list_enn(t_ennemy **head)
{
	t_ennemy	*tmp;

	while ((*head) != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	free(*head);
}

void	destroy_img_b(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->coll_1);
	mlx_destroy_image(vars->mlx, vars->coll_2);
	mlx_destroy_image(vars->mlx, vars->coll_3);
	mlx_destroy_image(vars->mlx, vars->coll_4);
	mlx_destroy_image(vars->mlx, vars->coll_5);
	mlx_destroy_image(vars->mlx, vars->coll_6);
	if (vars->coll != vars->coll_1 && vars->coll != vars->coll_2
		&& vars->coll != vars->coll_3 && vars->coll != vars->coll_4
		&& vars->coll != vars->coll_5 && vars->coll != vars->coll_6)
		mlx_destroy_image(vars->mlx, vars->coll);
	mlx_destroy_image(vars->mlx, vars->enn_1);
	mlx_destroy_image(vars->mlx, vars->enn_2);
	mlx_destroy_image(vars->mlx, vars->enn_3);
	mlx_destroy_image(vars->mlx, vars->enn_4);
	if (vars->enn != vars->enn_1 && vars->enn != vars->enn_2
		&& vars->enn != vars->enn_3 && vars->enn != vars->enn_4)
		mlx_destroy_image(vars->mlx, vars->enn);
}

void	destroy_img(t_vars *vars, int i)
{
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->character_1);
	mlx_destroy_image(vars->mlx, vars->character_2);
	mlx_destroy_image(vars->mlx, vars->character_3);
	mlx_destroy_image(vars->mlx, vars->character_4);
	mlx_destroy_image(vars->mlx, vars->door_c);
	mlx_destroy_image(vars->mlx, vars->door_o);
	if (i == 0)
		mlx_destroy_image(vars->mlx, vars->coll);
	if (vars->character != vars->character_1
		&& vars->character != vars->character_2
		&& vars->character != vars->character_3
		&& vars->character != vars->character_4)
		mlx_destroy_image(vars->mlx, vars->character);
	if (i == 1)
		destroy_img_b(vars);
}

void	count_lines_col(int *col, int *lines, char **map)
{
	*lines = 0;
	while (map[*lines])
	{
		*col = 0;
		while (map[*lines][*col])
		{
			(*col)++;
		}
		(*lines)++;
	}
}
