/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:05:23 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/03/04 18:12:02 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<unistd.h>
# include<limits.h>
# include<fcntl.h>
# include<stdlib.h>
# include<string.h>
# include<stdio.h>
# include<mlx.h>
# include"libft/libft.h"
# include"ft_printf/ft_printf.h"
# include <time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_ennemy
{
	int				x;
	int				y;
	struct s_ennemy	*next;
}	t_ennemy;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			x_of_p;
	int			y_of_p;
	char		**map;
	int			c;
	void		*wall;
	void		*character;
	void		*character_1;
	void		*character_2;
	void		*character_3;
	void		*character_4;
	void		*door_c;
	void		*door_o;
	void		*coll;
	void		*coll_1;
	void		*coll_2;
	void		*coll_3;
	void		*coll_4;
	void		*coll_5;
	void		*coll_6;
	void		*enn;
	void		*enn_1;
	void		*enn_2;
	void		*enn_3;
	void		*enn_4;
	int			count_move;
	int			n;
	t_ennemy	*ennemy;
	t_ennemy	*save_enn;
}	t_vars;

int			ft_printf(const char *s, ...);

char		*get_next_line(int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t count, size_t size);

t_list		*get_the_map(char **av, int ac);

int			map_contain_c_p_e(t_list *head_of_map, int lines, int col);

int			valid_path(char *str, int lines, int col);

void		ft_free_split(char ***str);
void		free_list(t_list **head, int k);
char		*ft_strjoin1(char *s1, char *s2, int k);
int			count_number_of_lines(t_list *head_of_map);
char		**switch_to_arr(t_list *head_of_map, char ***map);

void		free_list_enn(t_ennemy **head);
void		destroy_img(t_vars *vars, int i);

int			check_the_map(char *line, int number_of_lines, int max_of_lines);
int			check_the_map_b(char *line, int number_of_lines, int max_of_lines);

void		game(char **map);

int			move(int keycode, t_vars *vars);

int			move_b(int keycode, t_vars *vars);

void		set_images(t_vars *vars, int i, int bonus);
void		put_images(char **map, t_vars *vars, int i, int j);

t_ennemy	*ft_lstnew_enn(int i, int j);
void		get_pos_of_ennemy(char **map, t_ennemy **head, int i, int j);
void		count_lines_col(int *col, int *lines, char **map);

int			ennemy(t_vars *vars);

void		game_b(char **map);

#endif