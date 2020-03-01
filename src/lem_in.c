/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:48:21 by sroland           #+#    #+#             */
/*   Updated: 2020/03/01 20:18:15 by sroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

int			parse_input(t_graph *world)
{
	int		step;
	char	*line;

	step = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (step == 0 && get_ants(world, line, &step) != 1)
			return (-1);
		if (step == 1 && get_next_room(world, &line, &step) != 1)
			return (-1);
		if (step == 2)
			if (get_edges(world, line) != 1)
				return (-1);
		free(line);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_graph		*world;

	world = NULL;
	if (argc > 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (parse_input(world) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
}
