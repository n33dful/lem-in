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

#----------------------------- Make Targets -----------------------------------#

LIBFT=libft

#------------------------------- Lib Path -------------------------------------#

LIBFTPATH=libft
GNLPATH=get_next_line

#------------------------------------------------------------------------------#

all: $(LIBFT)

$(LIBFT):
	@make -C $(GNLPATH)
	@cp $(GNLPATH)/libft.a ./libft.a

clean:
	@make clean -C $(LIBFTPATH)
	@make clean -C $(GNLPATH)

fclean: clean
	@rm -f libft.a
	@make fclean -C $(LIBFTPATH)
	@make fclean -C $(GNLPATH)

re: fclean all

.PHONY: $(LIBFT)
