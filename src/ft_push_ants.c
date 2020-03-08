/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:08:37 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/08 21:04:36 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list		*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list		*ft_antnew(int index, t_list *road)
{
	t_list	*elem;
	t_ant	ant;

	ant.index = index;
	ant.road = road;
	if (!(elem = ft_lstnew(&ant, sizeof(t_ant))))
		return (NULL);
	return (elem);
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

static void		ft_lstdel_last1(t_list **lst)
{
	t_list	*pre_last;
	t_list	*ptr;

	ptr = (*lst);
	pre_last = NULL;
	if (ptr)
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
			free((*lst));
			(*lst) = NULL;
		}
		else
		{
			free(ptr);
			pre_last->next = NULL;
		}
	}
}

void		ft_dellong_roads(t_list **options, int number_of_ants)
{
	t_road	*road;

	if (*options)
	{
		while (1)
		{
			if (ft_lstlen(*options) == 1)
				break ;
			road = ft_lstlast((*options))->content;
			if (ft_sumofprelastroads(*options, road->len) < number_of_ants)
				break ;
			else
			{
				ft_lstdel_last1(options);
			}
		}
	}
}

void		ft_send_new_ants(int *total_ants, int *ant_index, \
t_list *list_of_roads, t_list **list_of_ants)
{
	t_road	*road;
	t_list	*new_ant;

	while (list_of_roads)
	{
		road = list_of_roads->content;
		if (!road->active_road || !*total_ants)
			break ;
		new_ant = ft_antnew(*ant_index, road->to);
		*ant_index += 1;
		*total_ants -= 1;
		ft_lstadd_back(list_of_ants, new_ant);
		list_of_roads = list_of_roads->next;
	}
}

static void	del(void *content, size_t content_size)
{
	return ;
}

t_list		*ft_del_the_end_ants(t_list *list_of_ants)
{
	t_list	*ptr;
	t_ant	*ant;

	if (list_of_ants)
	{
		ant = list_of_ants->content;
		if (!ant->road)
			list_of_ants = list_of_ants->next;
		if (!list_of_ants)
			return (NULL);
		else
			list_of_ants->next = \
ft_del_the_end_ants(list_of_ants->next);
		return (list_of_ants);
	}
	return (NULL);
}

static void	ft_print_ant(t_list *ant_elem)
{
	t_room	*room;
	t_ant	*ant;

	if (ant_elem)
	{
		ant = ant_elem->content;
		if (ant)
		{
			if (!ant->road)
				return ;
			room = ant->road->content;
			if (room)
			{
				ft_putchar('L');
				ft_putnbr(ant->index);
				ft_putstr(" - ");
				ft_putstr(room->name);
				ft_putchar(' ');
			}
		}
	}
}

static void	ft_move_ant(t_list *elem)
{
	t_ant	*ant;
	t_list	*ptr;

	if (elem)
	{
		ant = elem->content;
		if (ant->road)
			ant->road = ant->road->next;
	}
}

static void	ft_next_turn(t_list **list_of_ants)
{
	ft_lstiter(*list_of_ants, ft_print_ant);
	ft_lstiter(*list_of_ants, ft_move_ant);
	ft_putchar('\n');
	*list_of_ants = ft_del_the_end_ants(*list_of_ants);
}

void		ft_push_ants(t_calc *calc, t_graph *world)
{
	int		ants;
	int		ant_index;
	t_list	*list_of_ants;
	t_list	*new_ant;

	ant_index = 1;
	ants = world->number_of_ants;
	list_of_ants = NULL;
	while (ants)
	{
		ft_dellong_roads(&calc->roads, ants);
		ft_send_new_ants(&ants, &ant_index, calc->roads, &list_of_ants);
		ft_next_turn(&list_of_ants);
	}
	while (list_of_ants)
		ft_next_turn(&list_of_ants);
}
