/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:29:44 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/04 09:18:20 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_list	*head_of_map;
	char	**map;

	head_of_map = get_the_map(av, ac);
	if (!head_of_map)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	map = switch_to_arr(head_of_map, &map);
	game_b(map);
	return (0);
}
