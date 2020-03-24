
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
	is_optimal = ants_number;
	while (directions)
	{
		direction = directions->content;
		is_optimal = is_optimal - direction->len + 1;
		if (directions == current_direction)
			break ;
		directions = directions->next;
	}
	if (is_optimal < 0)
		return (0);
	return (1);
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
