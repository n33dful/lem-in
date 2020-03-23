# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 13:46:51 by cdarci            #+#    #+#              #
#    Updated: 2020/02/06 20:22:05 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=gcc
CCFLAGS=-Wall -Wextra -Werror
DFLAGS=-MD
DIR_S=src
DIR_O=tmp
DIR_H=incl
DIR_INT=integer_funcs
DIR_LST=list_funcs
DIR_MEM=memory_funcs
DIR_STR=string_funcs
DIR_GNL=get_next_line
INT_FILES=ft_atoi.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isblank.c\
ft_iscntrl.c\
ft_isdigit.c\
ft_isinteger.c\
ft_islower.c\
ft_isprint.c\
ft_isspace.c\
ft_isupper.c\
ft_putnbr_fd.c\
ft_putnbr.c\
ft_tolower.c\
ft_toupper.c
LST_FILES=ft_lstadd_back.c\
ft_lstadd_front.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstlast.c\
ft_lstlen.c\
ft_lstmap.c\
ft_lstmove.c\
ft_lstnew.c\
ft_lstsort.c
MEM_FILES=ft_arrdel.c\
ft_bzero.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c
STR_FILES=ft_itoa.c\
ft_putchar_fd.c\
ft_putchar.c\
ft_putendl_fd.c\
ft_putendl.c\
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
ft_strtrim.c
GNL_FILES=get_next_line.c
INT_SOURCES=$(addprefix $(DIR_S)/$(DIR_INT)/, $(INT_FILES))
INT_OBJECTS=$(addprefix $(DIR_O)/, $(INT_FILES:.c=.o))
LST_SOURCES=$(addprefix $(DIR_S)/$(DIR_LST)/, $(LST_FILES))
LST_OBJECTS=$(addprefix $(DIR_O)/, $(LST_FILES:.c=.o))
MEM_SOURCES=$(addprefix $(DIR_S)/$(DIR_MEM)/, $(MEM_FILES))
MEM_OBJECTS=$(addprefix $(DIR_O)/, $(MEM_FILES:.c=.o))
STR_SOURCES=$(addprefix $(DIR_S)/$(DIR_STR)/, $(STR_FILES))
STR_OBJECTS=$(addprefix $(DIR_O)/, $(STR_FILES:.c=.o))
GNL_SOURCES=$(addprefix $(DIR_S)/$(DIR_GNL)/, $(GNL_FILES))
GNL_OBJECTS=$(addprefix $(DIR_O)/, $(GNL_FILES:.c=.o))
ALL_OBJECTS=$(INT_OBJECTS) $(LST_OBJECTS) $(MEM_OBJECTS) \
$(STR_OBJECTS) $(GNL_OBJECTS)
D_OBJECTS=$(INT_OBJECTS:.o=.d) $(LST_OBJECTS:.o=.d) \
$(MEM_OBJECTS:.o=.d) $(STR_OBJECTS:.o=.d) $(GNL_OBJECTS:.o=.d)

all: $(NAME)

$(NAME): $(ALL_OBJECTS)
	@ar -rc $(NAME) $(ALL_OBJECTS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/$(DIR_INT)/%.c
	@mkdir -p $(DIR_O)
	$(CC) $(CCFLAGS) $(DFLAGS) -I$(DIR_H) -c $< -o $@

$(DIR_O)/%.o: $(DIR_S)/$(DIR_LST)/%.c
	@mkdir -p $(DIR_O)
	$(CC) $(CCFLAGS) $(DFLAGS) -I$(DIR_H) -c $< -o $@

$(DIR_O)/%.o: $(DIR_S)/$(DIR_MEM)/%.c
	@mkdir -p $(DIR_O)
	$(CC) $(CCFLAGS) $(DFLAGS) -I$(DIR_H) -c $< -o $@

$(DIR_O)/%.o: $(DIR_S)/$(DIR_STR)/%.c
	@mkdir -p $(DIR_O)
	$(CC) $(CCFLAGS) $(DFLAGS) -I$(DIR_H) -c $< -o $@

$(DIR_O)/%.o: $(DIR_S)/$(DIR_GNL)/%.c
	@mkdir -p $(DIR_O)
	$(CC) $(CCFLAGS) $(DFLAGS) -I$(DIR_H) -c $< -o $@
        
-include $(D_OBJECTS)

clean:
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
