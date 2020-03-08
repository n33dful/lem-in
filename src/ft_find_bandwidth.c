/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bandwidth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:08:37 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/08 19:15:43 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			if (edge->flow == 1)
				return (len + ft_roadlen(edge->to, end_room) + 1);
			edges = edges->next;
		}
		return (len);
	}
	return (-1);
}

static int	ft_sortroads(t_list *current, t_list *next)
{
	t_road	*first;
	t_road	*second;

	first = current->content;
	second = next->content;
	if (first->len > second->len)
		return (1);
	return (0);
}

static t_list	*road_room(t_room *room, t_room *end_room)
{
	t_list	*newwwwwwww;
	t_list	*new_elem;
	t_list	*edges;
	t_edge	*edge;

	newwwwwwww = NULL;
	if (room && end_room)
	{
		newwwwwwww = ft_lstnew(NULL, 0);
		newwwwwwww->content = room;
		edges = room->edges;
		while (edges)
		{
			edge = edges->content;
			if (ft_strequ(room->name, end_room->name))
			{
				new_elem = ft_lstnew(NULL, 0);
				new_elem->content = room;
				ft_lstadd_back(&newwwwwwww, new_elem);
				break ;
			}
			else if (edge->flow == 1)
			{
				edges = edge->to->edges;
				new_elem = ft_lstnew(NULL, 0);
				new_elem->content = edge->to;
				ft_lstadd_back(&newwwwwwww, new_elem);
			}
			edges = edges->next;
		}
	}
	return (newwwwwwww);
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
		edge = edges->content;
		if (edge->flow == 1)
		{
			road.to = road_room(edge->to, world->end_room->content);
			road.len = ft_roadlen(edge->to, world->end_room->content) + 1;
			road.active_road = 1;
			ft_lstadd_back(&options, ft_lstnew(&road, sizeof(t_road)));
		}
		edges = edges->next;
	}
	ft_lstsort(&options, ft_sortroads);
	return (options);
}

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

static int	ft_sumofprelastroads(t_list *options, int other)
{
	t_road	*road;
	int		sum;

	sum = 0;
	while (options)
	{
		road = options->content;
		sum = sum + other - road->len + 1;
		options = options->next;
		if (options && !options->next)
			break ;
	}
	return (sum);
}

t_calc		*ft_calc(t_graph *world)
{
	t_calc	*calc;
	t_road	*road;
	t_list	*opts;
	int		ants;
	int		turns;

	turns = 0;
	ants = world->number_of_ants;
	if (!(calc = (t_calc *)malloc(sizeof(t_calc))))
		return (NULL);
	calc->roads = ft_find_bandwidth(world);
	opts = ft_lstmap(calc->roads, ft_lstnew_pointer);
	while (ants)
	{
		while (1)
		{
			road = ft_lstlast(opts)->content;
			if (ft_lstlen(opts) == 1)
				break ;
			if (ft_sumofprelastroads(opts, road->len) < ants)
				break ;
			else
				ft_lstdel_last(&opts, ft_roomdel);
		}
		turns++;
		ants -= (int)ft_lstlen(opts);
	}
	turns += road->len - 1;
	calc->turns = turns;
	return (calc);
}
