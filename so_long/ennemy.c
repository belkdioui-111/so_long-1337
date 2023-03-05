/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:13:47 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/02/27 15:52:31 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_ennemy	*ft_lstnew_enn(int i, int j)
{
	t_ennemy	*str;

	str = (t_ennemy *)malloc (sizeof(t_ennemy));
	if (!str)
		return (NULL);
	str->x = i;
	str->y = j;
	str->next = NULL;
	return (str);
}

void	get_pos_of_ennemy(char **map, t_ennemy **head, int i, int j)
{
	t_ennemy	*tmp;
	t_ennemy	*new;

	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N')
			{
				if (*head == NULL)
				{
					*head = ft_lstnew_enn(i, j);
					tmp = *head;
				}
				else
				{
					new = ft_lstnew_enn(i, j);
					tmp->next = new;
					tmp = new;
				}
			}
		}
	}
}
