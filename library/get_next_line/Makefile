# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 13:46:51 by cdarci            #+#    #+#              #
#    Updated: 2020/02/06 20:16:57 by cdarci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C=gcc
NAME=libft.a
FLAGS=-Wall -Wextra -Werror
LIBFT=../libft
DIR_S=src
DIR_O=temp
HEADER=incl
SOURCES=get_next_line.c
SRCS=$(addprefix $(DIR_S)/,$(SOURCES))
OBJS=$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp $(LIBFT)/$(NAME) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(C) $(FLAGS) -I$(HEADER) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
