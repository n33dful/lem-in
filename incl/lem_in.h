/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:19:13 by sroland           #+#    #+#             */
/*   Updated: 2020/03/02 19:02:07 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../library/libft/incl/libft.h"
# include "../library/get_next_line/incl/get_next_line.h"
# include <limits.h>

typedef struct			room_struct
{
	char				*name;
	int					x;
	int					y;
	t_list				*edges;
	int					is_visited;
}						t_room;

typedef struct			edges_struct
{
	t_room				*to;
	int					weight;
	int					flow;
	int					residual;
}						t_edge;

typedef struct 			s_graph
{
	int					number_of_ants;
	t_list				*start_room;
	t_list				*end_room;
	t_list				*rooms;
}						t_graph;

int				parse_input(t_graph *world);
int				is_number(char *str);
int				ft_atoi_status(char **str, int *result);
int				get_ants(t_graph *world, char *line, int *step);
int				get_next_room(t_graph *world, char **line, int *step);
int				add_room(t_graph *world, int flag, char *line);
int				get_edges(t_graph *world, char *line);
void			ft_world_print(t_graph *world);

#endif
