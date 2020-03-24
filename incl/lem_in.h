/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <cdarci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:19:13 by sroland           #+#    #+#             */
/*   Updated: 2020/03/15 23:47:27 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <limits.h>
# include "lem_in_structs.h"
# include "libft.h"

/*
** ------------------------- Functions For Parsing -----------------------------
*/

int		ft_add_ants(t_graph *world, char *line, int *step);
int		ft_add_room(t_graph *world, char *line, int *step, int *room_type);
int		ft_add_edge(t_graph *world, char *line);
int		ft_check_graph(t_data *data);

/*
** ------------------------ Functions For Route Search -------------------------
*/

int		bfs_find_next_path(t_graph *world);
void	change_flow(int diff, t_room *from, t_room *leads_to);
int		bfs_travers(t_graph *world);
t_room	*room_out(t_room *room);
int		nulify_flow(t_graph *world);
int		nulify_parents_and_is_visited(t_graph *world);
int		ft_find_possible_ways(t_data *data);
void	ft_roomdel(void *content, size_t content_size);
t_list	*ft_find_directions(t_graph *world);
t_list	*ft_find_bandwidth(t_graph *world);
int		ft_send_ants(t_data *data);
int		ft_keep_optimal_directions(t_list *ways_list, int total_ants);
int		ft_read_line_format(const char *read_line);
int		ft_final_preparation(t_data *data);

/*
** --------------------- Functions For Delete List Content ---------------------
*/

void	ft_contentdel(void *content, size_t content_size);
void	ft_waydel(void *content, size_t content_size);
void	ft_bandwidthdel(void *content, size_t content_size);

#endif
