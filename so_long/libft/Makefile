# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 12:10:58 by bel-kdio          #+#    #+#              #
#    Updated: 2023/03/05 17:28:49 by bel-kdio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_memmove.c ft_atoi.c ft_memset.c ft_bzero.c	ft_putchar_fd.c \
	  ft_calloc.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_putstr_fd.c ft_split.c ft_strchr.c \
	  ft_strdup.c ft_itoa.c ft_striteri.c ft_strjoin.c\
	  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	  ft_strnstr.c ft_strrchr.c	ft_strtrim.c ft_substr.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c

OBJ = $(SRC:.c=.o)

SRC_B = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstsize.c

OBJ_B = $(SRC_B:.c=.o)


CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a 
AR = ar rc

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)

bonus : $(NAME) $(OBJ_B)
	@$(AR) $(NAME) $(OBJ_B)

clean :
	@rm -rf $(OBJ) $(OBJ_B)

fclean :
	@rm -rf $(NAME) $(OBJ) $(OBJ_B)

re: fclean $(NAME)
