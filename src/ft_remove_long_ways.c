
#include "lem_in.h"

static int		ft_sumofprelastroads(t_list *options, int other)
{
	t_way	*road;
	int		sum;

	sum = 0;
	while (options)
	{
		road = options->content;
		sum = sum + other - road->len + 1;
		if (options->next && !((t_way *)options->next->content)->active_way)
			break ;
		options = options->next;
	}
	return (sum);
}

static t_list	*ft_last_active_way(t_list *ways_list)
{
	t_list	*prev_node;

	prev_node = NULL;
    if (!ways_list)
		return (NULL);
    while (ways_list)
	{
		if (!((t_way *)ways_list->content)->active_way)
			break ;
        prev_node = ways_list;
        ways_list = ways_list->next;
    }
	return (prev_node);
}

static size_t	ft_active_ways_count(t_list *ways_list)
{
	t_way	*way;
	size_t	count;

	count = 0;
	while (ways_list)
	{
		way = ways_list->content;
		if (way->active_way)
			count++;
		ways_list = ways_list->next;
	}
	return (count);
}

void			ft_remove_long_ways(t_list *ways_list, int number_of_ants)
{
	t_way	*road;

	if (ways_list)
	{
		while (1)
		{
			if (ft_active_ways_count(ways_list) == 1)
				break ;
			road = ft_last_active_way(ways_list)->content;
			if (ft_sumofprelastroads(ways_list, road->len) < number_of_ants)
				break ;
			else
				road->active_way = 0;
		}
	}
}
