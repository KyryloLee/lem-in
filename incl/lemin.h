/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:33:22 by klee              #+#    #+#             */
/*   Updated: 2018/02/23 14:33:25 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

typedef struct	s_rooms
{
	char				*name;
	char				*x;
	char				*y;
	int					pos;
	struct s_rooms		*next;
}				t_rooms;

typedef struct	s_data
{
	unsigned int	numb;
	t_rooms			*rooms;
	char			**links;
}				t_input;

typedef struct	s_route
{
	char				*route;
	struct s_route		*next;
}				t_route;

int				read_input(t_input **res);
int				str_is_numb(char *str);
int				number_of_ants(t_input **data, char **line);
int				find_rooms(t_input **res);
int				valid_room(char *line, t_rooms **list_rooms);
int				make_new_room(t_rooms **list_rooms, char *line2, int index);
char			*beg_recursio(char *s, char c);
int				nmb_wrd(char *copy, char c);
void			clear_res_split(char ***tmp);
int				if_end_or_start(t_rooms **list_rooms, int	index);
int				add_new_rooms(t_rooms **list_rooms, char *line);
int				valid_links(char *line, t_rooms **list_rooms,\
t_input **res);
int				how_much_rooms(t_rooms *list_rooms);
char			**new_links(int numb_rooms, t_rooms **list_rooms);
int				right_room(char *line, t_rooms **list_rooms);
int				put_link(char *line, t_rooms **list_rooms, t_input **res);
int				both_rooms_and_defis(char *line, char *name1, char *name2);
void			put_link_list(char *line, t_rooms **list_rooms, t_input **res);
void			clean_links(char ***links);
int				same_rooms(t_rooms **list_rooms, char *line2, int index);
int				build_route(t_input *res);
int				all_routes(t_input *res, char **links);
int				find_start_or_end(t_rooms *list, int index);
int				recursio_find(char **links, int	index, t_route **all_ways);
t_route			*make_new_way(char **str);
void			add_way(t_route **all_ways, char **tmp);
void			del_one_way(t_route **find);
int				same_way(t_route *first, t_route *second);
void			del_same(t_route **all_ways);
int				after_point(t_route **tmp, t_route *find);
int				before_point(t_route **tmp, t_route *start);
void			correction_ways(t_route **all_ways);
void			clear_way_list(t_route **all_ways);
void			ways_with_end(t_route **all_ways, int end);
int				cmp_way(char *route, char *end_char);
char			*without_tail(char *str, char *end_char);
void			shortes_route(t_route **all_ways);
int				realy_short_way(char *way1, char *way2);
int				after_point_way(t_route *tmp, t_route *find);
int				before_point_way(t_route *tmp, t_route *start);
int				check_the_way(t_route *tmp, t_route *start);
int				count_the_same(char **s_way1, char **s_way2);
void			move_ants(t_route *all_way, t_input *res);
char			**change_name_of_room(t_route **all_way, t_input *res);
char			*find_name(t_rooms *n_room, int index);
void			display_moves(char **tmp, unsigned int index);
int				if_valid_minus(char **line, t_rooms **list_rooms,\
t_input **res);
int				wrong_number(void);
int				empty_file(void);
int				wrong_input_rooms(void);
int				wrong_input_links(void);
int				no_start_or_end(void);
int				not_enough_data(void);

#endif
