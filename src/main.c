/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:48:21 by sroland           #+#    #+#             */
/*   Updated: 2020/03/15 23:12:04 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_iscomment(const char *line, int *room_type, t_graph *world)
{
	if (line[0] != '#')
		return (0);
	else if (ft_strequ("##start", line) && !world->start_room)
		*room_type = start;
	else if (ft_strequ("##start", line) && world->start_room)
		return (0);
	else if (ft_strequ("##end", line) && !world->end_room)
		*room_type = end;
	else if (ft_strequ("##end", line) && world->end_room)
		return (0);
	return (1);
}

static int	ft_read_graph(t_data *data)
{
	t_list	*new;
	char	**line;
	int		room_type;
	int		step;

	step = 0;
	line = &data->read_line;
	room_type = middle;
	while (get_next_line(0, line) == 1)
	{
		if (!(new = ft_lstnew((*line), ft_strlen((*line)) + 1)))
			return (0);
		ft_lstadd_back(&data->input_map, new);
		if (ft_iscomment((*line), &room_type, &data->graph))
			continue ;
		if (step == 0 && ft_add_ants(&data->graph, (*line), &step))
			continue ;
		if (step == 1 && ft_add_room(&data->graph, (*line), &step, &room_type))
			continue ;
		if (step == 2 && ft_add_edge(&data->graph, (*line)))
			continue ;
		return (0);
	}
	return (1);
}

static void	ft_init_data(t_data *data)
{
	data->exit_code = 0;
	data->read_line = NULL;
	data->better_bandwidth = NULL;
	data->graph.end_room = NULL;
	data->graph.start_room = NULL;
	data->graph.number_of_ants = 0;
	data->graph.rooms = NULL;
	data->input_map = NULL;
	data->list_of_options = NULL;
}

static void	ft_del_data(t_data *data)
{
	ft_strdel(&data->read_line);
	ft_lstdel(&data->list_of_options, ft_bandwidthdel);
	ft_lstdel(&data->input_map, ft_contentdel);
	data->better_bandwidth = NULL;
	data->graph.start_room = NULL;
	data->graph.end_room = NULL;
	data->graph.number_of_ants = 0;
	ft_lstdel(&data->graph.rooms, ft_roomdel);
}

int			main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(&data);
	if (argc != 1 && argv)
		data.exit_code = 1;
	else if (!ft_read_graph(&data))
		data.exit_code = 1;
	else if (!ft_check_graph(&data))
		data.exit_code = 1;
	else if (!ft_find_possible_ways(&data))
		data.exit_code = 1;
	else if (!ft_send_ants(&data))
		data.exit_code = 1;
	ft_del_data(&data);
	if (data.exit_code == 1)
		ft_putendl_fd("Error", 2);
	return (data.exit_code);
}
