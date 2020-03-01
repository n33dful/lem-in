/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:19:13 by sroland           #+#    #+#             */
/*   Updated: 2020/03/01 17:00:25 by sroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../library/libft/incl/libft.h"
# include "../library/libft/incl/t_list.h"
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
	size_t				number_of_ants;
	char				*start_room;
	char				*end_room;
	t_list				*rooms;
}						t_graph;

int			parse_input(t_graph *world);
int			get_ants(t_graph *world, char *line);
int			get_next_room(t_graph *world, char *line);
int			get_edges(t_graph *world, char *line);
t_room		*find_room(t_graph *world, char *name);

#endif
