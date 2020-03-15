/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ford_falkerson_algo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:35:11 by sroland           #+#    #+#             */
/*   Updated: 2020/03/15 22:24:39 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			nulify_flow(t_graph *world)
{
	t_list		*room;
	t_list		*edge;

	room = world->rooms;
	while (room)
	{
		edge = ((t_room *)room->content)->edges;
		while (edge)
		{
			((t_edge *)edge->content)->flow = 0;
			((t_edge *)edge->content)->residual =
				((t_edge *)edge->content)->weight;
			edge = edge->next;
		}
		room = room->next;
	}
	return (1);
}

int			nulify_parents_and_is_visited(t_graph *world)
{
	t_list		*room;

	room = world->rooms;
	while (room)
	{
		((t_room *)room->content)->is_visited = 0;
		((t_room *)room->content)->parent = NULL;
		room = room->next;
	}
	return (0);
}

static void		ft_road_del(void *content, size_t content_size)
{
	if (content_size > 0)
		ft_memdel(&content);
}

static void		ft_del_option(void *content, size_t content_size)
{
	t_bandwidth	*calc;

	if (content_size > 0)
	{
		calc = content;
		ft_lstdel(&calc->roads, ft_road_del);
		ft_memdel(&content);
	}
}

t_list			*ford_falkerson(t_graph *world)
{
	t_list	*list_of_options;
	t_list	*new;

	list_of_options = NULL;
	nulify_flow(world);
	nulify_parents_and_is_visited(world);
	while (bfs_find_next_path(world) == 1)
	{
		if (!(new = ft_calc(world)))
		{
			ft_lstdel(&list_of_options, ft_del_option);
			return (NULL);
		}
		ft_lstadd_back(&list_of_options, new);
	}
	return (list_of_options);
}
