/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_breadth_first_search.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:59:46 by sroland           #+#    #+#             */
/*   Updated: 2020/03/04 22:38:38 by sroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

t_list				*delete_first_room(t_list **queue)
{
	t_list		*tmp;

	tmp = *queue;
	*queue = (*queue)->next;
	tmp->next = NULL;
	ft_lstdel(&tmp, ft_roomdel);
	return (*queue);
}

t_room				*room_out(t_room *room)
{
	t_list			*edge;

	edge = room->edges;
	while (edge)
	{
		if (((t_edge *)edge->content)->flow == 1)
			return (((t_edge *)edge->content)->to);
		edge = edge->next;
	}
	return (NULL);
}

static int			check_edges(t_list *edge, t_list *v_queue, t_graph *world)
{
	while (edge)
	{
		if (((t_edge *)(edge->content))->flow == 0 &&
			((t_edge *)(edge->content))->to->is_visited == 0 &&
			(room_out(((t_edge *)(edge->content))->to) == NULL ||
			room_out(((t_edge *)(edge->content))->to) ==
				(t_room *)(v_queue->content)))
		{
			((t_edge *)(edge->content))->to->is_visited = 1;
			((t_edge *)(edge->content))->to->parent =
				(t_room *)(v_queue->content);
			if (((t_edge *)(edge->content))->to ==
				(t_room *)(world->end_room->content))
				return (1);
			ft_lstadd_back(&v_queue,
				ft_lstnew(((t_edge *)(edge->content))->to, sizeof(t_room)));
		}
		edge = edge->next;
	}
	return (0);
}

void				print_queue(t_list *queue)
{
	int				i;

	i = 0;
	printf("\n\niteration\n");
	while (queue)
	{
		printf("room%3d  >>%8s\n", i, ((t_room *)(queue->content))->name);
		queue = queue->next;
		i++;
	}
}

int					bfs_travers(t_graph *world)
{
	t_list		*v_queue;
	t_list		*edge;

	v_queue = world->start_room;
	((t_room *)(world->start_room->content))->is_visited = 1;
	while (v_queue)
	{
		edge = ((t_room *)v_queue->content)->edges;
		if (check_edges(edge, v_queue, world) == 1)
			return (1);
		print_queue(v_queue);
		v_queue = delete_first_room(&v_queue);
	}
	return (0);
}

void				change_flow(int diff, t_room *from, t_room *to)
{
	t_list		*tmp_edge;

	tmp_edge = from->edges;
	while (tmp_edge)
	{
		if (((t_edge *)tmp_edge->content)->to == to)
		{
			((t_edge *)tmp_edge->content)->flow =
				((t_edge *)tmp_edge->content)->flow + diff;
			printf("flow from %10s to %10s = %5d\n", from->name, to->name,
				((t_edge *)tmp_edge->content)->flow);
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
	tmp = (t_room *)world->end_room->content;
	printf("\n\ngreat news!! Path found\n\n");
	while (tmp->parent)
	{
		printf("room name: %20s; parent: %20s\n", tmp->name,
			tmp->parent->name);
		change_flow(-1, tmp, tmp->parent);
		change_flow(1, tmp->parent, tmp);
		tmp = tmp->parent;
	}
	nulify_parents_and_is_visited(world);
	return (1);
}
