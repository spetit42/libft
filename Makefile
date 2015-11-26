#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spetit <spetit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 18:17:14 by spetit            #+#    #+#              #
#    Updated: 2014/11/04 18:17:15 by spetit           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= libft.a

GCCFLAG		= gcc -Wall -Wextra -Werror

SRCS		= ft_atoi.c ft_putnbr.c ft_strcmp.c ft_strcpy.c ft_strdup.c\
			ft_strlen.c ft_strncmp.c ft_strncpy.c ft_putchar.c ft_putstr.c\
			ft_strcat.c ft_bzero.c ft_memcpy.c ft_memset.c ft_strncat.c\
			ft_strstr.c ft_memccpy.c ft_strlcat.c ft_memmove.c ft_memcmp.c\
			ft_memchr.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_isalpha.c\
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
			ft_tolower.c ft_memalloc.c ft_memdel.c ft_putendl.c ft_strdel.c\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
			ft_strnew.c ft_strjoin.c ft_strclr.c ft_striter.c ft_striteri.c\
			ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
			ft_strtrim.c ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c\
			ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c get_next_line.c\
			ft_list_push_front.c ft_create_elem.c ft_list_push_back.c

SRCS_O		= $(SRCS:.c=.o)

all:	$(NAME)


$(NAME):
		$(GCCFLAG) -c $(SRCS)
		ar rc $(NAME) $(SRCS_O)
		ranlib $(NAME)

clean:
		rm -f $(SRCS_O)
		rm -f libft.h.gch

fclean: clean
		rm -f $(NAME)

re:	fclean all