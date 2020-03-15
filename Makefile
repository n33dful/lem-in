# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/01 16:14:55 by cdarci            #+#    #+#              #
#    Updated: 2020/03/15 23:10:38 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lem-in
CC=gcc
CCFLAGS=-Wall -Wextra -Werror -g
DFLAGS=-MD
FILES=lem_in.c\
parse_content.c\
get_number.c\
get_edges.c\
ft_breadth_first_search.c\
ft_ford_falkerson_algo.c\
ft_graphdel.c\
ft_find_bandwidth.c\
ft_push_ants.c\
ft_lstdel_func.c
DIR_S=src
DIR_O=tmp
DIR_H=incl
DIR_LIB=library
DIR_H_LIB=library/incl
SOURCES=$(addprefix $(DIR_S)/, $(FILES))
OBJECTS=$(addprefix $(DIR_O)/, $(FILES:.c=.o))
DFILES=$(OBJECTS:.o=.d)

all: $(NAME)
	@make -C library > /dev/null

$(NAME): $(OBJECTS)
	@make -C library > /dev/null
	@$(CC) $(OBJECTS) -L$(DIR_LIB) -lft -o $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(CCFLAGS) $(DFLAGS) -I$(DIR_H_LIB) -I$(DIR_H) -c $< -o $@

-include $(DFILES)

clean:
	@make clean -C library > /dev/null
	@rm -rf $(DIR_O)

fclean: clean
	@make fclean -C library > /dev/null
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
