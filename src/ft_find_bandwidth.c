/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bandwidth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:08:37 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/04 21:33:31 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_reset_is_visited(t_list *elem)
{
	t_room	*room;

	room = elem->content;
	room->is_visited = 0;
}

static int	ft_roadlen(t_room *room, t_room *end_room)
{
	t_list	*edges;
	t_edge	*edge;
	int		len;

	if (room && end_room)
	{
		len = 0;
		edges = room->edges;
		if (ft_strequ(room->name, end_room->name))
			return (0);
		while (edges)
		{
			edge = edges->content;
			room->is_visited = 1;
			if (edge->flow && !edge->to->is_visited)
				return (len + ft_roadlen(edge->to, end_room) + 1);
			edges = edges->next;
		}
		return (len);
	}
	return (-1);
}


t_list		*ft_find_bandwidth(t_graph *world)
{
	t_room	*start_room;
	t_list	*edges;
	t_edge	*edge;
	t_road	road;
	t_list	*options;

	start_room = world->start_room->content;
	edges = start_room->edges;
	options = NULL;
	while (edges)
	{
		start_room->is_visited = 1;
		edge = edges->content;
		road.to = edge->to;
		road.len = ft_roadlen(edge->to, world->end_room->content) + 1;
		ft_lstadd_back(&options, ft_lstnew(&road, sizeof(t_road)));
		ft_lstiter(world->rooms, ft_reset_is_visited);
		edges = edges->next;
	}
	ft_lstiter(world->rooms, ft_reset_is_visited);
	return (options);
}
