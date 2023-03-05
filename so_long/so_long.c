/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:05:20 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/05 21:13:17 by bel-kdio         ###   ########.fr       */
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
		return (2);
	}
	map = switch_to_arr(head_of_map, &map);
	game(map);
	return (0);
}
