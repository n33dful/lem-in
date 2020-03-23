/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bandwidth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:08:37 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:18:49 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_add_room_way(t_list **rooms_way, t_room *room)
{
	t_list	*new_elem;

	if (!(new_elem = ft_lstnew(NULL, 0)))
	{
		ft_lstdel(rooms_way, ft_contentdel);
		return (0);
	}
	new_elem->content = room;
	ft_lstadd_back(rooms_way, new_elem);
	return (1);
}

static t_list	*ft_rooms_way(t_room *room, t_room *end_room)
{
	t_list	*rooms_way;
	t_list	*edges;

	rooms_way = NULL;
	if (room && end_room)
	{
		edges = room->edges;
		while (edges)
		{
			if (ft_strequ(room->name, end_room->name) || \
((t_edge *)edges->content)->flow == 1)
			{
				if (!(ft_add_room_way(&rooms_way, room)))
					return (NULL);
				if (ft_strequ(room->name, end_room->name))
					break ;
				room = ((t_edge *)edges->content)->to;
				edges = room->edges;
			}
			else
				edges = edges->next;
		}
	}
	return (rooms_way);
}

static int		ft_add_way(t_list **list_of_bandwidth, \
t_list *edges, t_graph *world)
{
	t_list	*new_elem;
	t_way	way;

	way.direction = ft_rooms_way(((t_edge *)edges->content)->to, \
world->end_room->content);
	way.len = ft_lstlen(way.direction);
	way.active_way = 1;
	if (!(new_elem = ft_lstnew(&way, sizeof(t_way))))
	{
		ft_lstdel(list_of_bandwidth, ft_contentdel);
		return (0);
	}
	ft_lstadd_back(list_of_bandwidth, new_elem);
	return (1);
}

static int		ft_sort_ways(t_list *current, t_list *next)
{
	t_way	*first;
	t_way	*second;

	first = current->content;
	second = next->content;
	if (first->len > second->len)
		return (1);
	return (0);
}

t_list			*ft_find_directions(t_graph *world)
{
	t_room	*start_room;
	t_list	*list_of_bandwidth;
	t_list	*edges;

	start_room = world->start_room->content;
	edges = start_room->edges;
	list_of_bandwidth = NULL;
	while (edges)
	{
		if (((t_edge *)edges->content)->flow == 1)
		{
			if (!ft_add_way(&list_of_bandwidth, edges, world))
				return (NULL);
		}
		edges = edges->next;
	}
	ft_lstsort(&list_of_bandwidth, ft_sort_ways);
	return (list_of_bandwidth);
}

/*
** To another file
*/

t_list		*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list		*ft_lstnew_pointer(t_list *elem)
{
	t_list	*lst;

	if ((lst = ft_lstnew(NULL, 0)))
		lst->content = elem->content;
	return (lst);
}

void		ft_lstdel_last(t_list **lst, void (*del)(void *, size_t))
{
	t_list	*pre_last;
	t_list	*ptr;

	ptr = (*lst);
	pre_last = NULL;
	if (ptr && del)
	{
		while (ptr->next)
		{
			pre_last = ptr;
			ptr = ptr->next;
			if (!ptr->next)
				break ;
		}
		if (!pre_last)
		{
			del((*lst)->content, (*lst)->content_size);
			free((*lst));
			(*lst) = NULL;
		}
		else
		{
			del(ptr->content, ptr->content_size);
			free(ptr);
			pre_last->next = NULL;
		}
	}
}

static void	ft_set_active_ways(t_list *elem)
{
	t_way	*way;

	way = elem->content;
	if (way)
		way->active_way = 1;
}

static size_t	ft_active_ways_count(t_list *ways_list)
{
	t_way	*way;
	size_t	count;

	count = 0;
	while (ways_list)
	{
		way = ways_list->content;
		if (!way)
			return (0);
		if (way->active_way)
			count++;
		ways_list = ways_list->next;
	}
	return (count);
}

t_list		*ft_calc(t_graph *world)
{
	t_bandwidth	calc;
	int			ants;
	int			turns;

	turns = 0;
	ants = world->number_of_ants;
	calc.roads = ft_find_directions(world);
	while (ants)
	{
		ft_remove_long_ways(calc.roads, ants);
		ants -= (int)ft_active_ways_count(calc.roads);
		turns++;
	}
	ft_lstiter(calc.roads, ft_set_active_ways);
	turns += ((t_way *)calc.roads->content)->len - 1;
	calc.turns = turns;
	return (ft_lstnew(&calc, sizeof(t_bandwidth)));
}
