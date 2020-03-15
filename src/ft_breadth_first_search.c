/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_breadth_first_search.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:59:46 by sroland           #+#    #+#             */
/*   Updated: 2020/03/14 18:28:03 by cdarci           ###   ########.fr       */
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
	free(tmp);
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

int					room_inflow(t_room *room)
{
	t_list			*edge;
	int				count;

	edge = room->edges;
	count = 0;
	while (edge)
	{
		if (((t_edge *)edge->content)->flow == -1)
			count++;
		edge = edge->next;
	}
	return (count);
}

static int			check_edges(t_list *edge, t_list *v_queue, t_graph *world)
{
	t_list			*new;

//	printf("\nvertex: %s\n", ((t_room *)(v_queue->content))->name);
	while (edge)
	{
//		printf("%10s\n", ((t_room *)((t_edge *)(edge->content))->to)->name);
		if (((t_edge *)(edge->content))->flow <= 0 &&
			((t_edge *)(edge->content))->to->is_visited == 0 &&
			(room_inflow((t_room *)(v_queue->content)) <= 1 ||
			((t_edge *)(edge->content))->flow == -1))
		{
//			printf("\tedge to: %s\n", ((t_edge *)(edge->content))->to->name);
			((t_edge *)(edge->content))->to->is_visited = 1;
			((t_edge *)(edge->content))->to->parent =
				(t_room *)(v_queue->content);
			if (((t_edge *)(edge->content))->to ==
				(t_room *)(world->end_room->content))
			{
//				printf("\tEND FOUND!!!!\n\n");
				return (1);
			}
			new = malloc(sizeof(t_list));
			new->content = (t_room *)(((t_edge *)(edge->content))->to);
			new->content_size = sizeof(t_room *);
			new->next = NULL;
			ft_lstadd_back(&v_queue, new);
		}
		edge = edge->next;
	}
	return (0);
}

void				print_queue(t_list *queue)
{
	int				i;

	i = 0;
	printf("\n\nqueue status>>>\n");
	while (queue)
	{
		printf("room%3d  >>%8s  (parent %8s)\n", i,
			((t_room *)(queue->content))->name,
			(((t_room *)(queue->content))->parent == NULL ? "NULL" :
			((t_room *)(queue->content))->parent->name));
		queue = queue->next;
		printf("moved >>\n");
		i++;
	}
}

int					bfs_travers(t_graph *world)
{
	t_list		*v_queue;
	t_list		*edge;

	v_queue = malloc(sizeof(t_list));
	v_queue->content = world->start_room->content;
	v_queue->content_size = sizeof(t_room *);
	v_queue->next = NULL;
	((t_room *)(world->start_room->content))->is_visited = 1;
	while (v_queue)
	{
		edge = ((t_room *)(v_queue->content))->edges;
		if (check_edges(edge, v_queue, world) == 1)
		{
//			print_queue(v_queue);
			return (1);
		}
//		print_queue(v_queue);
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
	while (tmp->parent)
	{
		change_flow(-1, tmp, tmp->parent);
		change_flow(1, tmp->parent, tmp);
		tmp = tmp->parent;
	}
	nulify_parents_and_is_visited(world);
	return (1);
}
