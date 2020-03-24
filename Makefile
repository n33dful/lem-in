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
FILES=main.c\
ft_add_ants.c\
ft_add_edge.c\
ft_add_room.c\
ft_breadth_first_search.c\
ft_find_possible_ways.c\
ft_find_bandwidth.c\
ft_send_ants.c\
ft_lstdel_funcs.c\
ft_check_graph.c\
ft_keep_optimal_directions.c\
ft_read_line_format.c\
ft_final_preparation.c\
ft_find_directions.c
DIR_S=src
DIR_O=tmp
DIR_H=incl
DIR_LIB=lib
DIR_H_LIB=lib/incl
SOURCES=$(addprefix $(DIR_S)/, $(FILES))
OBJECTS=$(addprefix $(DIR_O)/, $(FILES:.c=.o))
DFILES=$(OBJECTS:.o=.d)

all: $(NAME)
	@make -C $(DIR_LIB) > /dev/null

$(NAME): $(OBJECTS)
	@make -C $(DIR_LIB) > /dev/null
	@$(CC) $(OBJECTS) -L$(DIR_LIB) -lft -o $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(CCFLAGS) $(DFLAGS) -I$(DIR_H_LIB) -I$(DIR_H) -c $< -o $@

-include $(DFILES)

clean:
	@make clean -C $(DIR_LIB) > /dev/null
	@rm -rf $(DIR_O)

fclean: clean
	@make fclean -C $(DIR_LIB) > /dev/null
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
