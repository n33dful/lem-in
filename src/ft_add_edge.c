/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:51:41 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/31 18:58:49 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*ft_find_room(char *room_name, t_list *rooms)
{
	t_room	*room;

	room = NULL;
	if (room_name && rooms)
	{
		while (rooms)
		{
			room = rooms->content;
			if (ft_strequ(room_name, room->name))
				break ;
			rooms = rooms->next;
		}
	}
	return (room);
}

static int		ft_add(char *from, char *to, t_list *rooms)
{
	t_room	*room_to;
	t_room	*room_from;
	t_list	*new_elem;
	t_edge	edge;

	if (!from || !to || !rooms)
		return (0);
	if (!(room_from = ft_find_room(from, rooms)))
		return (0);
	if (!(room_to = ft_find_room(to, rooms)))
		return (0);
	edge.weight = 0;
	edge.residual = 0;
	edge.flow = 0;
	edge.leads_to = room_to;
	if (!(new_elem = ft_lstnew(&edge, sizeof(t_edge))))
		return (0);
	ft_lstadd_back(&room_from->edges, new_elem);
	return (1);
}

static int		ft_edge_exists(char **room_names, t_list *rooms)
{
	t_room	*room;
	t_edge	*edge;
	t_list	*edges_list;

	if (!room_names || !room_names[0] || !room_names[1] || !rooms)
		return (1);
	while (rooms)
	{
		room = rooms->content;
		if (ft_strequ(room->name, room_names[0]))
		{
			edges_list = room->edges;
			while (edges_list)
			{
				edge = edges_list->content;
				if (ft_strequ(edge->leads_to->name, room_names[1]))
					return (1);
				edges_list = edges_list->next;
			}
		}
		rooms = rooms->next;
	}
	return (0);
}

int				ft_add_edge(t_graph *world, char *line)
{
	int		exit_code;
	char	**room_names;

	exit_code = 1;
	room_names = NULL;
	if (line)
	{
		if (ft_read_line_format(line) != edge_format)
			exit_code = 0;
		else if (!(room_names = ft_strsplit(line, '-')))
			exit_code = 0;
		else if (ft_edge_exists(room_names, world->rooms))
			exit_code = 0;
		else if (!ft_add(room_names[0], room_names[1], world->rooms))
			exit_code = 0;
		else if (!ft_add(room_names[1], room_names[0], world->rooms))
			exit_code = 0;
		ft_arrdel((void *)(&room_names));
		return (exit_code);
	}
	return (0);
}
