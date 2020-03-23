
#ifndef LEM_IN_STRUCTS
# define LEM_IN_STRUCTS

# include "libft.h"

typedef enum		e_read_line_type
{
	incorrect_format,
	room_format,
	edge_format
}					t_read_line_type;

typedef enum		e_room_type
{
	middle,
	start,
	end
}					t_room_type;

typedef struct		s_bandwidth
{
	int				turns;
	t_list			*roads;
}					t_bandwidth;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				type;
	t_list			*edges;
	int				is_visited;
	struct s_room	*parent;
}					t_room;

typedef struct		s_edges_struct
{
	t_room			*to;
	int				weight;
	int				flow;
	int				residual;
}					t_edge;

typedef struct		s_graph
{
	int				number_of_ants;
	t_list			*start_room;
	t_list			*end_room;
	t_list			*rooms;
}					t_graph;

typedef struct		s_way
{
	t_list			*direction;
	size_t			len;
	int				active_way;
}					t_way;

typedef struct		s_ant
{
	size_t			index;
	t_list			*current_room;
}					t_ant;

typedef struct		s_data
{
	int				exit_code;
	char			*read_line;
	t_bandwidth		*better_bandwidth;
	t_graph			graph;
	t_list			*input_map;
	t_list			*list_of_options;
}					t_data;

#endif
