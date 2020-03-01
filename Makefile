# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/01 16:14:55 by cdarci            #+#    #+#              #
#    Updated: 2020/03/01 20:20:02 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C=gcc
FLAGS=-g
FILES=lem_in.c\
parse_content.c\
get_number.c\
get_edges.c\
ft_world_print.c\
basic_operations.c
NAME=lem-in
DIR_S=src
DIR_O=tmp
HEADER=incl
SOURCES=$(addprefix $(DIR_S)/, $(FILES))
OBJECTS=$(addprefix $(DIR_O)/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(C) $(FLAGS) $(OBJECTS) -o $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p $(DIR_O)
	$(C) $(FLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -rf $(DIR_O)

fclen:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
