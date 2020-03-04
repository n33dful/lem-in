/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:19:13 by sroland           #+#    #+#             */
/*   Updated: 2020/03/04 21:34:31 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../library/libft/incl/libft.h"
# include "../library/get_next_line/incl/get_next_line.h"
# include <limits.h>

typedef struct			s_road
{		
	t_room				*to;
	int					len;
}						t_road;

typedef struct			s_calc
{		
	int					turns;
	t_list				*roads;
}						t_calc;

typedef struct			s_room_struct
{
	char				*name;
	int					x;
	int					y;
	t_list				*edges;
	int					is_visited;
	t_room				*parent;
}						t_room;

typedef struct			s_edges_struct
{
	t_room				*to;
	int					weight;
	int					flow;
	int					residual;
}						t_edge;

typedef struct			s_graph
{
	int					number_of_ants;
	t_list				*start_room;
	t_list				*end_room;
	t_list				*rooms;
}						t_graph;

int						parse_input(t_graph *world);
int						is_number(char *str);
int						ft_atoi_status(char **str, int *result);
int						get_ants(t_graph *world, char *line, int *step);
int						get_next_room(t_graph *world, char **line, int *step);
int						add_room(t_graph *world, int flag, char *line);
int						get_edges(t_graph *world, char *line);
void					ft_world_print(t_graph *world);
void					ft_graphdel(t_graph *graph);

int						bfs_find_next_path(t_graph *world);
void					change_flow(int diff, t_room *from, t_room *to);
int						bfs_travers(t_graph *world);
t_room					*room_out(t_room *room);
t_list					*delete_first_room(t_list **queue);
int						nulify_flow(t_graph *world);
int						nulify_parents_and_is_visited(t_graph *world);
int						ford_falkerson(t_graph *world);
void					ft_roomdel(void *content, size_t content_size);

t_list					*ft_find_bandwidth(t_graph *world);

#endif
