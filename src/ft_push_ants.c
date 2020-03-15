/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:08:37 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:19:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static t_list	*ft_antnew(int index, t_list *road)
{
	t_list	*elem;
	t_ant	ant;

	ant.index = index;
	ant.current_room = road;
	if (!(elem = ft_lstnew(&ant, sizeof(t_ant))))
		return (NULL);
	return (elem);
}

static int		ft_sumofprelastroads(t_list *options, int other)
{
	t_way	*road;
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
	t_way	*road;

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

static int		ft_send_new_ants(int *total_ants, int *ant_index, \
t_list *list_of_roads, t_list **list_of_ants)
{
	t_way	*road;
	t_list	*new_ant;

	while (list_of_roads)
	{
		road = list_of_roads->content;
		if (!road->active_way || !*total_ants)
			break ;
		if (!(new_ant = ft_antnew(*ant_index, road->direction)))
		{
			ft_lstdel(list_of_ants, ft_lstdel_func);
			return (0);
		}
		*ant_index += 1;
		*total_ants -= 1;
		ft_lstadd_back(list_of_ants, new_ant);
		list_of_roads = list_of_roads->next;
	}
	return (1);
}

static void	ft_remove_extinct_ants(t_list **list_of_ants)
{
	t_list	*head;
	t_list	*ptr_next;
	t_ant	*ant;

	head = NULL;
	while ((*list_of_ants))
	{
		ptr_next = (*list_of_ants)->next;
		ant = (*list_of_ants)->content;
		if (!ant->current_room)
		{
			ft_memdel(&(*list_of_ants)->content);
			ft_memdel((void *)(&(*list_of_ants)));
			(*list_of_ants) = ptr_next;
			continue ;
		}
		(*list_of_ants)->next = NULL;
		ft_lstadd_back(&head, (*list_of_ants));
		(*list_of_ants) = ptr_next;
	}
	(*list_of_ants) = head;
}

static void	ft_print_ants(t_list *list_of_ants)
{
	t_room	*room;
	t_ant	*ant;

	while (list_of_ants)
	{
		ant = list_of_ants->content;
		room = ant->current_room->content;
		ft_putchar('L');
		ft_putnbr(ant->index);
		ft_putstr("-");
		ft_putstr(room->name);
		if (list_of_ants->next)
			ft_putchar(' ');
		list_of_ants = list_of_ants->next;
	}
}

static void	ft_move_ants(t_list *elem)
{
	t_ant	*ant;

	if (elem)
	{
		ant = elem->content;
		if (ant->current_room)
			ant->current_room = ant->current_room->next;
	}
}

int			ft_push_ants(t_bandwidth *bandwidth, t_graph *world)
{
	int		ants;
	int		ant_index;
	t_list	*list_of_ants;

	ant_index = 1;
	ants = world->number_of_ants;
	list_of_ants = NULL;
	while (list_of_ants || ants)
	{
		ft_dellong_roads(&bandwidth->roads, ants);
		if (!(ft_send_new_ants(&ants, &ant_index, \
bandwidth->roads, &list_of_ants)))
			return (0);
		ft_print_ants(list_of_ants);
		ft_lstiter(list_of_ants, ft_move_ants);
		ft_putchar('\n');
		ft_remove_extinct_ants(&list_of_ants);
	}
	return (1);
}
