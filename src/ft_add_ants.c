
#include "lem_in.h"

int	ft_add_ants(t_graph *world, char *line, int *step)
{
	if (ft_isinteger(line) != 1)
		return (0);
	if (!ft_isdigit(line[ft_strlen(line) - 1]))
		return (0);
	world->total_ants = ft_atoi(line);
	if (world->total_ants <= 0)
		return (0);
	*step = 1;
	return (1);
}
