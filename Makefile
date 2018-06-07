# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 11:30:04 by klee              #+#    #+#              #
#    Updated: 2018/02/23 11:30:07 by klee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS_PREFIX = ./srcs
SRCS = lemin.c \
		read_input.c\
		read_input1.c\
		read_input2.c\
		read_input3.c\
		read_input4.c\
		read_input5.c\
		build_route.c\
		build_route1.c\
		build_route2.c\
		build_route3.c\
		build_route4.c
SRCS_DIR = $(addprefix $(SRCS_PREFIX)/, $(SRCS))
OBJ = $(SRCS:.c=.o)
LIB = ./libft/libft.a
INCL = ./incl

all:$(NAME)
$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(FLAGS) -I $(INCL) -I libft/includes -c $(SRCS_DIR)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
$(OBJ): $(SRCS_DIR)
	$(CC) $(FLAGS) -I $(INCL) -I libft/includes -c $<
dbug:
	$(CC) -I $(INCL) -I libft/includes -g $(SRCS_DIR) $(LIB) -o $(NAME)
clean:
	rm -f $(OBJ)
	make clean -C libft/
fclean: clean
	make fclean -C libft/
	rm -f $(NAME)
re: fclean all