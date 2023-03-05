/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 07:56:35 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/02/27 16:10:25 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_split(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		free((*str)[i]);
		i++;
	}
	free(*str);
}

void	free_list(t_list **head, int k)
{
	t_list	*tmp;

	while ((*head) != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		if (!k)
			free(tmp->content);
		free(tmp);
	}
	free(*head);
}

char	*ft_strjoin1(char *s1, char *s2, int k)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	if (k != 1)
		free(s1);
	return (str);
}

int	count_number_of_lines(t_list *head_of_map)
{
	int	count;

	count = 0;
	while (head_of_map->next)
	{
		head_of_map = head_of_map->next;
		count++;
	}
	return (count);
}

char	**switch_to_arr(t_list *head_of_map, char ***map)
{
	t_list	*tmp;
	char	*str;
	int		i;

	tmp = head_of_map;
	str = tmp->content;
	tmp = tmp->next;
	i = 0;
	i++;
	while (tmp)
	{
		str = ft_strjoin1(str, tmp->content, i);
		tmp = tmp->next;
		i++;
	}
	free_list(&head_of_map, 0);
	*map = ft_split(str, '\n');
	free(str);
	return (*map);
}
