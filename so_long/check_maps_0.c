/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:01:59 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/05 21:30:32 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_of_map(t_list *head_of_map, int number_of_lines)
{
	size_t	len;
	t_list	*tmp;

	tmp = head_of_map;
	len = ft_strlen(head_of_map->content) - 1;
	while (head_of_map->next && number_of_lines)
	{
		if (len != ft_strlen(head_of_map->content) - 1)
		{
			free_list(&tmp, 0);
			return (0);
		}
		number_of_lines--;
		head_of_map = head_of_map->next;
	}
	if (len != ft_strlen(head_of_map->content))
	{
		free_list(&tmp, 0);
		return (0);
	}
	return (1);
}

t_list	*get_lines(int fd, int *number_of_lines)
{
	t_list	*head_of_map;
	t_list	*tmp;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	head_of_map = ft_lstnew(line);
	tmp = head_of_map;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp->next = ft_lstnew(line);
		tmp = tmp->next;
		(*number_of_lines)++;
	}
	return (head_of_map);
}

int	check_the_file_name(char **av, int ac)
{
	int		fd;
	char	*ext;

	if (ac <= 1 || ac > 2)
		return (0);
	ext = ft_strchr(av[1], '.');
	if (!ext)
		return (0);
	if (ft_strncmp(ext, ".ber\0", 5))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	return (fd);
}

t_list	*verification(int ac, char **av, int *number_of_lines)
{
	int		fd;
	t_list	*head_of_map;

	fd = check_the_file_name(av, ac);
	if (!fd || fd == -1)
	{
		ft_printf("error in file descriptor\n");
		return (0);
	}
	head_of_map = get_lines(fd, number_of_lines);
	if (!head_of_map)
		return (0);
	if (!len_of_map(head_of_map, *number_of_lines))
	{
		ft_printf("error in lenth of lines\n");
		return (0);
	}
	if (!map_contain_c_p_e(head_of_map, *number_of_lines
			, ft_strlen(head_of_map->content) - 1))
	{
		ft_printf("there is an error in C or P or E\n");
		return (0);
	}
	return (head_of_map);
}

t_list	*get_the_map(char **av, int ac)
{
	t_list	*head_of_map;
	int		number_of_lines;
	t_list	*tmp;
	int		number_of_lines_fix;

	number_of_lines = 0;
	head_of_map = verification(ac, av, &number_of_lines);
	number_of_lines_fix = number_of_lines;
	tmp = head_of_map;
	while (tmp)
	{
		if (!(check_the_map((tmp->content), number_of_lines,
					number_of_lines_fix)))
		{
			free_list(&head_of_map, 0);
			return (0);
		}
		tmp = tmp->next;
		number_of_lines--;
	}
	return (head_of_map);
}
