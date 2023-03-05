# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 08:05:27 by bel-kdio          #+#    #+#              #
#    Updated: 2023/03/05 17:27:49 by bel-kdio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = so_long.c check_maps_0.c check_maps_1.c get_next_line.c check_c_p_e_valide_path.c utils.c utils_1.c valide_path.c game.c set_and_print_images.c move.c
SRC_B = so_long_bonus.c check_maps_bonus_0.c check_maps_bonus_1.c get_next_line.c check_c_p_e_valide_path.c utils.c utils_1.c valide_path.c ennemy.c move_ennemy.c game_b.c move_b_player.c set_and_print_images.c

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = so_long
BONUS = so_long_bonus

all : $(NAME)

$(NAME) : $(OBJ)
	@make bonus -C libft/
	@make -C ft_printf/
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(LIBFT) $(PRINTF) -o $(NAME)

$(BONUS) : $(OBJ_B)
	@make bonus -C libft/
	@make -C ft_printf/
	$(CC) $(CFLAGS) $(OBJ_B) -lmlx -framework OpenGL -framework AppKit $(LIBFT) $(PRINTF) -o $(NAME)
	
bonus : $(BONUS)
	
clean :
	rm -rf $(OBJ) $(OBJ_B)
	@make clean -C libft/
	@make clean -C ft_printf/

fclean : clean
	rm -rf $(NAME) $(BONUS)
	@make fclean -C libft/
	@make fclean -C ft_printf/

re : fclean $(NAME)