/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:08:37 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/15 23:19:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_lstpop(t_list **lst, void (*del)(void*, size_t))
{
    t_list	*current_node = NULL;
	t_list	*prev_node = NULL;

    if (!lst || !(*lst) || !del)
		return ;
    current_node = (*lst); 
    while (current_node->next)
	{
        prev_node = current_node;
        current_node = current_node->next;
    }
    if (!prev_node)
		ft_memdel((void *)lst);
	else
	{
		del(current_node->content, current_node->content_size);
		ft_memdel((void *)(&current_node));
		prev_node->next = NULL;
    }
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

static int		ft_send_new_ants(int *total_ants, \
t_list *ways_list, t_list **ants_list)
{
	static size_t	ant_index;
	t_list			*new_ant;
	t_way			*way;

	if (ways_list || total_ants)
	{
		while (ways_list)
		{
			way = ways_list->content;
			if (!way->active_way || !(*total_ants))
				break ;
			if (!(new_ant = ft_antnew(++ant_index, way->direction)))
			{
				ft_lstdel(ants_list, ft_contentdel);
				return (0);
			}
			(*total_ants) = (*total_ants) - 1;
			ft_lstadd_back(ants_list, new_ant);
			ways_list = ways_list->next;
		}
		return (1);
	}
	return (0);
}

static void	ft_remove_extinct_ants(t_list **ants_list)
{
	t_list	*head;
	t_list	*ptr_next;
	t_ant	*ant;

	head = NULL;
	while ((*ants_list))
	{
		ptr_next = (*ants_list)->next;
		ant = (*ants_list)->content;
		if (!ant->current_room)
		{
			ft_memdel(&(*ants_list)->content);
			ft_memdel((void *)(&(*ants_list)));
			(*ants_list) = ptr_next;
			continue ;
		}
		(*ants_list)->next = NULL;
		ft_lstadd_back(&head, (*ants_list));
		(*ants_list) = ptr_next;
	}
	(*ants_list) = head;
}

static void	ft_print_ants(t_list *ants_list)
{
	t_room	*room;
	t_ant	*ant;

	if (ants_list)
	{
		while (ants_list)
		{
			ant = ants_list->content;
			room = ant->current_room->content;
			ft_putchar('L');
			ft_putnbr(ant->index);
			ft_putstr("-");
			ft_putstr(room->name);
			if (ants_list->next)
				ft_putchar(' ');
			ants_list = ants_list->next;
		}
		ft_putchar('\n');
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

static void	ft_print_world(t_list *list_elem)
{
	char	*str;

	str = list_elem->content;
	if (str)
		ft_putendl(str);
}

static t_bandwidth	*ft_find_best_option(t_list *list_of_options)
{
	t_bandwidth	*min_option;
	int			min_turns;

	min_turns = ((t_bandwidth *)list_of_options->content)->turns;
	min_option = list_of_options->content;
	while (list_of_options)
	{
		if (((t_bandwidth *)list_of_options->content)->turns < min_turns)
		{
			min_option = list_of_options->content;
			min_turns = ((t_bandwidth *)list_of_options->content)->turns;
		}
		list_of_options = list_of_options->next;
	}
	return (min_option);
}

int					ft_send_ants(t_data *data)
{
	int			total_ants;
	t_list		*ants_list;
	t_bandwidth	*bandwidth;

	ft_lstiter(data->input_map, ft_print_world);
	ft_putchar('\n');
	ants_list = NULL;
	total_ants = data->graph.number_of_ants;
	bandwidth = ft_find_best_option(data->list_of_options);
	while (ants_list || total_ants)
	{
		ft_remove_long_ways(bandwidth->roads, total_ants);
		if (!(ft_send_new_ants(&total_ants, \
bandwidth->roads, &ants_list)))
			return (0);
		ft_print_ants(ants_list);
		ft_lstiter(ants_list, ft_move_ants);
		ft_remove_extinct_ants(&ants_list);
	}
	return (1);
}
