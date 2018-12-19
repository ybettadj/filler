# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/26 01:21:53 by ybettadj          #+#    #+#              #
#    Updated: 2018/04/26 01:21:55 by ybettadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = ybettadj.filler

LIBFT = ./libft/libft.a

SRC =	./src/filler.c get_next_line/get_next_line.c ./src/init_begin.c \
		./src/init_new.c ./src/initstru.c ./src/cut_piece.c ./src/check_zone.c \
		./src/place_piece.c ./src/size.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) -o $(NAME) $(FLAGS) $(LIBFT) $(OBJ) -g

clean :
	make clean -C ./libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C ./libft
	rm -f $(NAME)

re : fclean all
