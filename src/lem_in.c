/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:48:21 by sroland           #+#    #+#             */
/*   Updated: 2020/03/06 23:21:36 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			parse_input(t_graph *world)
{
	int		step;
	char	*line;

	step = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (step == 0)
		{
			if (get_ants(world, line, &step) != 1)
				return (-1);
		}
		else if (step == 1 && get_next_room(world, &line, &step) != 1)
			return (-1);
		if (step == 2 &&
		(!world->start_room || !world->end_room || get_edges(world, line) != 1))
				return (-1);
		free(line);
	}
	return (1);
}

int			init_world(t_graph *world)
{
	world->end_room = NULL;
	world->start_room = NULL;
	world->number_of_ants = 0;
	world->rooms = NULL;
	return (0);
}

void		algo_magic(t_graph *world)
{
	t_calc	*calc;

	calc = ft_calc(world);
	printf("ants will pass it for %d turn(s)\n", calc->turns);
	//ft_lstdel(&calc->roads, ft_roomdel);
	free(calc);
}

int			main(int argc, char **argv)
{
	t_graph		world;
	t_calc		*calc;

	init_world(&world);
	if (argc > 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (parse_input(&world) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_world_print(&world);
	ford_falkerson(&world);
	algo_magic(&world);
	ft_graphdel(&world);
	return (0);
}
