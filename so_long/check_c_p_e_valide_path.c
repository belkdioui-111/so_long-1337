/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c_p_e_valide_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:26:30 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/02/25 21:48:11 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_c_p_e(char *line, int *C, int *P, int *E)
{
	while (*line)
	{
		if (*line == 'C')
			(*C)++;
		else if (*line == 'P')
			(*P)++;
		else if (*line == 'E')
			(*E)++;
		line++;
	}
}

int	valid_check(t_list **head_of_map)
{
	int		c;
	int		p;
	int		e;
	t_list	*tmp;

	c = 0;
	p = 0;
	e = 0;
	tmp = *head_of_map;
	while (tmp)
	{
		check_c_p_e(tmp->content, &c, &p, &e);
		tmp = tmp->next;
	}
	if (e != 1 || c < 1 || p != 1)
	{
		free_list(head_of_map, 0);
		return (0);
	}
	return (1);
}

int	map_contain_c_p_e(t_list *head_of_map, int lines, int col)
{
	int		e;
	t_list	*tmp;
	char	*str;

	tmp = head_of_map;
	if (!valid_check(&head_of_map))
		return (0);
	str = tmp->content;
	tmp = tmp->next;
	e = 0;
	e++;
	while (tmp)
	{
		str = ft_strjoin1(str, tmp->content, e);
		tmp = tmp->next;
		e++;
	}
	if (!valid_path(str, lines, col))
	{
		free_list(&head_of_map, 1);
		return (0);
	}
	return (1);
}
