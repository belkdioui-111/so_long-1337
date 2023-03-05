# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 09:05:12 by bel-kdio          #+#    #+#              #
#    Updated: 2023/03/05 17:28:31 by bel-kdio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_printf_putchar.c ft_printf_putstr.c ft_printf_putnbr.c ft_printf_u.c ft_printf_hexa.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
NAME = libftprintf.a
AR = ar rc

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean :
	@rm -rf $(OBJ)
fclean :
	@rm -rf $(OBJ) $(NAME)
re: fclean $(NAME)
	
	


