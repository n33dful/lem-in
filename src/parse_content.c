/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroland <sroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:47:33 by sroland           #+#    #+#             */
/*   Updated: 2020/03/01 17:23:36 by sroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_ants(t_graph *world, char *line)
{
	if (is_number(line) == 0)
		return (0);
	if (ft_atoi_status(&line, world->number_of_ants) == 0)
		return (0);
	while (ft_isspace1((int)(*line)) != 0)
		line++;
	if (*line != '\0')
		return (0);
	return (1);
}

int			get_next_room(t_graph *world, char *line)
{
	int		flag;

	flag = 0;
	if (ft_strequ(line, "##start") == 1)
		flag = 1;
	else if (ft_strequ(line, "##end") == 1)
		flag = 100;
	else if (*line == '#')
		flag = -1;
	if (add_room(t_graph *world, int flag, char *line) == )



	
}

int			get_edges(t_graph *world, char *line)
{
	
}