# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybettadj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 20:11:01 by ybettadj          #+#    #+#              #
#    Updated: 2017/12/08 06:30:02 by ybettadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIR_SRC = ./

DIR_OBJ = ./obj

SRC_1 =	ft_atoi.c     ft_strlcat.c    ft_memset.c\
		ft_memcpy.c   ft_memmove.c    ft_memchr.c\
		ft_memalloc.c ft_bzero.c      ft_memdel.c\
		ft_strdel.c   ft_strclr.c     ft_striter.c\
		ft_striteri.c ft_putchar.c    ft_putstr.c\
		ft_putnbr.c   ft_putchar_fd.c ft_putstr_fd.c\
		ft_putendl.c  ft_putnbr_fd.c  ft_strdup.c\
		ft_strcpy.c   ft_strncpy.c    ft_strcat.c\
		ft_strncat.c  ft_strchr.c     ft_strrchr.c\
		ft_strstr.c   ft_strsub.c     ft_putendl_fd.c\
		ft_strjoin.c  ft_strtrim.c    ft_memccpy.c\
		ft_itoa.c	  ft_strnew.c     ft_strmap.c\
		ft_strmapi.c  ft_memcmp.c     ft_strlen.c\
		ft_strcmp.c   ft_strncmp.c    ft_atoi.c\
		ft_isalpha.c  ft_isdigit.c    ft_isalnum.c\
		ft_isascii.c  ft_isprint.c    ft_toupper.c\
		ft_tolower.c  ft_strequ.c     ft_strnequ.c\
		ft_strnstr.c  ft_strsplit.c   ft_count.c\
		ft_range.c    ft_split_whitespaces.c\
		ft_ultimate_range.c   ft_print_words_tables.c\
		ft_lstadd.c   ft_lstiter.c    ft_lstdelone.c\
		ft_lstdel.c   ft_lstnew.c     ft_lstmap.c\

SRC = $(addprefix $(DIR_SRC)/, $(SRC_1))

OBJ = $(addprefix $(DIR_OBJ)/, $(SRC_1:.c=.o))

VPATH = $(DIR_SRC)

HEADER = ./

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) libft.h Makefile
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(DIR_OBJ)/%.o: %.c
	@mkdir -p $(DIR_OBJ)
	@gcc -I $(HEADER) $(FLAG) -c $< -o $@

clean:
	/bin/rm -rf ./obj

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
