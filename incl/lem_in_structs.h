/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konstantinzakharov <konstantinzakharov@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:50:29 by student           #+#    #+#             */
/*   Updated: 2020/04/03 23:24:37 by konstantinz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_STRUCTS_H
# define LEM_IN_STRUCTS_H

# include "libft.h"

typedef enum		e_read_line_type
{
	incorrect_format,
	room_format,
	edge_format
}					t_read_line_type;

typedef enum		e_room_type
{
	ordinary_room,
	start_room,
	end_room
}					t_room_type;

typedef struct		s_bandwidth
{
	int				turns_required;
	t_list			*directions;
}					t_bandwidth;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				type;
	t_list			*edges;
	int				is_visited;
	struct s_room	*parent;
}					t_room;

typedef struct		s_edge
{
	t_room			*leads_to;
	int				weight;
	int				flow;
	int				residual;
}					t_edge;

typedef struct		s_graph
{
	int				total_ants;
	t_room			*start_room;
	t_room			*end_room;
	t_list			*rooms;
}					t_graph;

typedef struct		s_direction
{
	t_list			*way;
	size_t			len;
	int				active;
}					t_direction;

typedef struct		s_ant
{
	size_t			number;
	t_list			*current_room;
}					t_ant;

typedef struct		s_data
{
	int				exit_code;
	char			*read_line;
	t_graph			graph;
	t_list			*entered_map;
	t_list			*bandwidths_list;
	t_bandwidth		*better_bandwidth;
}					t_data;

#endif
