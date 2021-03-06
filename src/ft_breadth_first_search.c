/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_breadth_firts_search.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:51:41 by sroland           #+#    #+#             */
/*   Updated: 2020/03/31 18:58:49 by sroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			is_valid_edge(t_list *edge, t_list **v_queue)
{
	if (((room_inflow((t_room *)((*v_queue)->content)) == 1 &&
		((t_edge *)(edge->content))->flow == -1) ||
		room_inflow((t_room *)((*v_queue)->content)) < 1) &&
		((t_edge *)(edge->content))->flow <= 0 &&
		((t_edge *)(edge->content))->leads_to->is_visited == 0)
		return (1);
	return (0);
}

static int			check_edges(t_list *edge, t_list **v_queue, t_graph *world)
{
	t_list			*new;

	while (edge)
	{
		if (is_valid_edge(edge, v_queue) == 1)
		{
			((t_edge *)(edge->content))->leads_to->is_visited = 1;
			((t_edge *)(edge->content))->leads_to->parent =
				(t_room *)((*v_queue)->content);
			if (((t_edge *)(edge->content))->leads_to ==
				(t_room *)(world->end_room))
				return (1);
			new = (t_list *)malloc(sizeof(t_list));
			new->content = (t_room *)(((t_edge *)(edge->content))->leads_to);
			new->content_size = 0;
			new->next = NULL;
			ft_lstadd_back(v_queue, new);
		}
		edge = edge->next;
	}
	return (0);
}

int					bfs_travers(t_graph *world)
{
	t_list		*v_queue;
	t_list		*edge;

	v_queue = malloc(sizeof(t_list));
	v_queue->content = world->start_room;
	v_queue->content_size = 0;
	v_queue->next = NULL;
	((t_room *)(world->start_room))->is_visited = 1;
	while (v_queue)
	{
		edge = ((t_room *)(v_queue->content))->edges;
		if (check_edges(edge, &v_queue, world) == 1)
		{
			ft_lstdel(&v_queue, ft_contentdel);
			return (1);
		}
		delete_first_room(&v_queue);
	}
	return (0);
}

void				change_flow(int diff, t_room *from, t_room *leads_to)
{
	t_list		*tmp_edge;

	tmp_edge = from->edges;
	while (tmp_edge)
	{
		if (((t_edge *)tmp_edge->content)->leads_to == leads_to)
		{
			((t_edge *)tmp_edge->content)->flow =
				((t_edge *)tmp_edge->content)->flow + diff;
		}
		tmp_edge = tmp_edge->next;
	}
}

int					bfs_find_next_path(t_graph *world)
{
	t_room		*tmp;

	if (bfs_travers(world) == 0)
	{
		nulify_parents_and_is_visited(world);
		return (0);
	}
	tmp = (t_room *)world->end_room;
	while (tmp->parent)
	{
		change_flow(-1, tmp, tmp->parent);
		change_flow(1, tmp->parent, tmp);
		tmp = tmp->parent;
	}
	nulify_parents_and_is_visited(world);
	return (1);
}
