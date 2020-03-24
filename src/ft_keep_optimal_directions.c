
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
	int			sum;

	if (directions == current_direction)
		return (1);
	sum = 0;
	while (directions)
	{
		if (directions == current_direction)
			break ;
		direction = directions->content;
		sum += ants_number - direction->len + 1;
		directions = directions->next;
	}
	if (sum < ants_number)
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
