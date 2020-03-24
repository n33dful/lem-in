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

static int	ft_send_new_ants(int *total_ants, t_list *directions, t_list **ants)
{
	static size_t	ant_number;
	t_list			*new_ant;
	t_direction		*direction;
	t_ant			ant;

	if (!(*total_ants))
		return (1);
	while (directions)
	{
		direction = directions->content;
		if (!direction->active)
			break ;
		ant.number = ++ant_number;
		ant.current_room = direction->way;
		if (!(new_ant = ft_lstnew(&ant, sizeof(t_ant))))
			return (0);
		(*total_ants) -= 1;
		ft_lstadd_back(ants, new_ant);
		directions = directions->next;
	}
	return (1);
}

static void	ft_remove_extinct_ants(t_list **ants)
{
	t_list	*head;
	t_list	*ptr_next;
	t_ant	*ant;

	head = NULL;
	while ((*ants))
	{
		ptr_next = (*ants)->next;
		ant = (*ants)->content;
		if (!ant->current_room)
		{
			ft_memdel(&(*ants)->content);
			ft_memdel((void *)(&(*ants)));
			(*ants) = ptr_next;
			continue ;
		}
		(*ants)->next = NULL;
		ft_lstadd_back(&head, (*ants));
		(*ants) = ptr_next;
	}
	(*ants) = head;
}

static void	ft_print_ant(t_list *ants)
{
	t_room	*room;
	t_ant	*ant;

	if (ants)
	{
		ant = ants->content;
		room = ant->current_room->content;
		ft_putchar('L');
		ft_putnbr(ant->number);
		ft_putstr("-");
		ft_putstr(room->name);
		if (ants->next)
			ft_putchar(' ');
		else
			ft_putchar('\n');
	}
}

static void	ft_move_ant(t_list *ants)
{
	t_ant	*ant;

	if (ants)
	{
		ant = ants->content;
		if (ant->current_room)
			ant->current_room = ant->current_room->next;
	}
}

int			ft_send_ants(t_data *data)
{
	t_list		*ants;
	t_bandwidth	*bandwidth;

	ants = NULL;
	bandwidth = data->better_bandwidth;
	while (ants || data->graph.total_ants)
	{
		ft_keep_optimal_directions(bandwidth->directions, \
data->graph.total_ants);
		if (!(ft_send_new_ants(&data->graph.total_ants, \
bandwidth->directions, &ants)))
		{
			ft_lstdel(&ants, ft_contentdel);
			return (0);
		}
		ft_lstiter(ants, ft_print_ant);
		ft_lstiter(ants, ft_move_ant);
		ft_remove_extinct_ants(&ants);
	}
	return (1);
}
