/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:21:56 by klee              #+#    #+#             */
/*   Updated: 2018/03/12 11:22:01 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			build_route(t_input *res)
{
	char		**links;
	t_rooms		*list_rooms;

	list_rooms = res->rooms;
	links = res->links;
	if (!links)
		return (wrong_input_links());
	if (!list_rooms)
		return (-1);
	if (find_start_or_end(list_rooms, 0) < 0\
	|| find_start_or_end(list_rooms, 2) < 0)
		return (-1);
	if (all_routes(res, links))
		return (-1);
	return (0);
}

int			all_routes(t_input *res, char **links)
{
	int				start;
	t_route			*all_ways;
	int				end;
	char			*route;

	route = ft_strnew(1);
	all_ways = make_new_way(&route);
	start = find_start_or_end(res->rooms, 0);
	end = find_start_or_end(res->rooms, 2);
	recursio_find(links, start, &all_ways);
	del_same(&all_ways);
	correction_ways(&all_ways);
	ways_with_end(&all_ways, end);
	shortes_route(&all_ways);
	move_ants(all_ways, res);
	clear_way_list(&all_ways);
	return (0);
}

int			find_start_or_end(t_rooms *list, int index)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (list)
	{
		if (list->pos == index)
		{
			c++;
			break ;
		}
		list = list->next;
		i++;
	}
	return (!c ? -1 : i);
}

int			recursio_find(char **links, int index, t_route **all_ways)
{
	int				i;
	char			*index_char;
	char			*i_char;
	char			*tmp;

	i = 0;
	index_char = ft_itoa(index);
	ft_join_free(&(*all_ways)->route, index_char);
	ft_join_free(&(*all_ways)->route, "-");
	while (links[index][i])
	{
		i_char = ft_itoa(i);
		if (links[index][i] == '1')
		{
			tmp = ft_strdup((*all_ways)->route);
			if (!ft_strstr(((*all_ways)->route), i_char))
				recursio_find(links, i, all_ways);
			ft_strchr(links[index] + i + 1, '1') ? add_way(all_ways, &tmp) :
			free(tmp);
		}
		free(i_char);
		i++;
	}
	free(index_char);
	return (0);
}

t_route		*make_new_way(char **str)
{
	t_route	*new;

	new = (t_route*)malloc(sizeof(t_route));
	new->route = *str;
	new->next = NULL;
	return (new);
}
