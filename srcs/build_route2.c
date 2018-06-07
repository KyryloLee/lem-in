/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_route2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:30:16 by klee              #+#    #+#             */
/*   Updated: 2018/03/20 15:30:17 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			realy_short_way(char *way1, char *way2)
{
	int		i;

	i = 0;
	if (ft_strlen(way1) > ft_strlen(way2))
		i = 1;
	return (i);
}

int			after_point_way(t_route *tmp, t_route *find)
{
	while (find)
	{
		if (realy_short_way(tmp->route, find->route))
			return (0);
		find = find->next;
	}
	return (1);
}

int			before_point_way(t_route *tmp, t_route *start)
{
	while (start != tmp)
	{
		if (realy_short_way(tmp->route, start->route))
			return (0);
		start = start->next;
	}
	return (1);
}

char		*without_tail(char *str, char *end_char)
{
	char	*res;
	char	**tmp;
	int		i;

	i = 0;
	res = ft_strnew(1);
	tmp = ft_strsplit(str, '-');
	while (ft_strcmp(tmp[i], end_char))
	{
		ft_join_free(&res, tmp[i]);
		ft_join_free(&res, "-");
		i++;
	}
	ft_join_free(&res, tmp[i]);
	clear_res_split(&tmp);
	return (res);
}

void		shortes_route(t_route **all_ways)
{
	t_route		*tmp1;
	t_route		*start;
	t_route		*new;
	char		*buf;

	tmp1 = *all_ways;
	start = *all_ways;
	new = NULL;
	while (tmp1)
	{
		if (check_the_way(tmp1, start))
		{
			buf = ft_strdup(tmp1->route);
			add_way(&new, &buf);
		}
		tmp1 = tmp1->next;
	}
	tmp1 = *all_ways;
	*all_ways = new;
	clear_way_list(&tmp1);
	del_same(all_ways);
	correction_ways(all_ways);
}
