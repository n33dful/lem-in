/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:48:21 by sroland           #+#    #+#             */
/*   Updated: 2020/03/02 19:53:58 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//t_list		*room_new(char *name, int x, int y)
//{
//	t_room	room;
//	t_list	*new;
//
//	room.x = x;
//	room.y = y;
//	room.is_visited = 0;
//	room.name = ft_strdup(name);
//	room.edges = NULL;
//	if (!(new = ft_lstnew(&room, sizeof(t_room))))
//		return (NULL);
//	return (new);
//}
//
//t_graph		*graph_example()
//{
//	t_graph	*graph;
//	t_list	*new;
//	t_room	room;
//
//	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
//		return (NULL);
//	graph->rooms = NULL;
//	new = room_new("1", 0, 0);
//	ft_lstadd_back(&graph->rooms, new);
//	new = room_new("2", 0, 0);
//	graph->start_room = new;
//	ft_lstadd_back(&graph->rooms, new);
//	new = room_new("3", 0, 0);
//	ft_lstadd_back(&graph->rooms, new);
//	new = room_new("4", 0, 0);
//	graph->end_room = new;
//	ft_lstadd_back(&graph->rooms, new);
//	return (graph);
//}

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
	t_graph		world;

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
}
