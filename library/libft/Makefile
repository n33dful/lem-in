# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 13:46:51 by cdarci            #+#    #+#              #
#    Updated: 2020/01/06 18:37:53 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C=gcc
NAME=libft.a
FLAGS=-Wall -Wextra -Werror
DIR_S=src
DIR_O=temp
HEADER=incl
SOURCES=ft_atoi.c\
ft_bzero.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isblank.c\
ft_iscntrl.c\
ft_isdigit.c\
ft_islower.c\
ft_isprint.c\
ft_isspace.c\
ft_isupper.c\
ft_itoa.c\
ft_lstadd_back.c\
ft_lstadd_front.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstlen.c\
ft_lstmap.c\
ft_lstmove.c\
ft_lstnew.c\
ft_lstsort.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putchar.c\
ft_putendl_fd.c\
ft_putendl.c\
ft_putnbr_fd.c\
ft_putnbr.c\
ft_putstr_fd.c\
ft_putstr.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_tolower.c\
ft_toupper.c
SRCS=$(addprefix $(DIR_S)/,$(SOURCES))
OBJS=$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(C) $(FLAGS) -I$(HEADER) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
