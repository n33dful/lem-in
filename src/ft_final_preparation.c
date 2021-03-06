/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_perparation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:51:41 by cdarci            #+#    #+#             */
/*   Updated: 2020/03/31 18:58:49 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bandwidth	*ft_find_best_bandwidth(t_list *bandwidths_list)
{
	t_bandwidth	*current_bandwidth;
	t_bandwidth	*better_bandwidth;
	int			min_turns;

	better_bandwidth = NULL;
	if (bandwidths_list)
	{
		current_bandwidth = bandwidths_list->content;
		better_bandwidth = current_bandwidth;
		min_turns = better_bandwidth->turns_required;
		while (bandwidths_list)
		{
			current_bandwidth = bandwidths_list->content;
			if (current_bandwidth->turns_required < min_turns)
			{
				better_bandwidth = current_bandwidth;
				min_turns = better_bandwidth->turns_required;
			}
			bandwidths_list = bandwidths_list->next;
		}
	}
	return (better_bandwidth);
}

static void			ft_print_map_line(t_list *entered_map)
{
	char	*str;

	if (entered_map)
	{
		if ((str = entered_map->content))
			ft_putendl(str);
		if (!entered_map->next)
			ft_putchar('\n');
	}
}

int					ft_final_preparation(t_data *data)
{
	if (!(data->better_bandwidth = \
ft_find_best_bandwidth(data->bandwidths_list)))
		return (0);
	ft_lstiter(data->entered_map, ft_print_map_line);
	return (1);
}
