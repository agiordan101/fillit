# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/24 19:07:38 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2018/12/04 17:36:34 by agiordan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit 
FILE =	fillit.c \
		parse.c \
		algo.c \
		ft_list.c \
		fct.c
OBJ = $(FILE:%.c=%.o)
HEADER = fillit.h
LIBFT = libft/libft.a
CC = gcc
CFLAGS =  -Wextra -Wall -Werror

all: $(NAME)
		
$(NAME): $(OBJ)
		make -C libft
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		rm -f $(OBJ)
		make clean -C libft/

fclean: clean
		rm -f $(NAME)
		make fclean -C libft/

re: fclean all
