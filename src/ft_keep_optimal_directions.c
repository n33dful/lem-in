/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_optimal_directions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konstantinzakharov <konstantinzakharov@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:59:04 by student           #+#    #+#             */
/*   Updated: 2020/04/01 16:09:41 by konstantinz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_active_ways_count(t_list *directions)
{
	t_direction	*way;
	int			count;

	count = 0;
	while (directions)
	{
		way = directions->content;
		if (way->active)
			count++;
		directions = directions->next;
	}
	return (count);
}

static int	ft_isoptimal(t_list *directions, \
t_list *current_direction, int ants_number)
{
	t_direction	*direction;
	int			is_optimal;

	if (directions == current_direction)
		return (1);
	is_optimal = 0;
	while (directions)
	{
		direction = directions->content;
		is_optimal = is_optimal +
			((t_direction *)current_direction->content)->len -
			direction->len + 1;
		directions = directions->next;
		if (directions == current_direction)
			break ;
	}
	if (is_optimal < ants_number)
		return (1);
	return (0);
}

int			ft_keep_optimal_directions(t_list *directions, int ants_number)
{
	t_list		*first_direction;
	t_direction	*direction;

	first_direction = directions;
	while (directions)
	{
		direction = directions->content;
		if (!ft_isoptimal(first_direction, directions, ants_number))
			direction->active = 0;
		else
			direction->active = 1;
		directions = directions->next;
	}
	return (ft_active_ways_count(first_direction));
}
