# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/01 16:14:55 by cdarci            #+#    #+#              #
#    Updated: 2020/03/06 22:09:55 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C=gcc
FLAGS=-g
FILES=lem_in.c\
parse_content.c\
get_number.c\
get_edges.c\
ft_world_print.c\
ft_breadth_first_search.c\
ft_ford_falkerson_algo.c\
ft_graphdel.c\
ft_find_bandwidth.c
NAME=lem-in
DIR_S=src
DIR_O=tmp
HEADER=incl
SOURCES=$(addprefix $(DIR_S)/, $(FILES))
OBJECTS=$(addprefix $(DIR_O)/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C library
	@$(C) $(FLAGS) $(OBJECTS) -Llibrary -lft -o $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(C) $(FLAGS) -I$(HEADER) -c $< -o $@

clean:
	@make clean -C library
	@rm -rf $(DIR_O)

fclean: clean
	@make fclean -C library
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
