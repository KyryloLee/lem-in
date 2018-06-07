/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_route4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:35:06 by klee              #+#    #+#             */
/*   Updated: 2018/03/20 15:35:08 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			before_point(t_route **tmp, t_route *start)
{
	while (start != *tmp)
	{
		if (!same_way(*tmp, start))
		{
			return (1);
		}
		start = start->next;
	}
	return (0);
}

int			same_way(t_route *first, t_route *second)
{
	int		dif;
	int		res;

	dif = 0;
	if (!ft_strlen(first->route) || !ft_strlen(second->route))
		return (-1);
	dif = ft_strlen(first->route);
	res = ft_strncmp(first->route, second->route, dif);
	return (res);
}

void		add_way(t_route **all_ways, char **tmp)
{
	t_route *new;

	new = make_new_way(tmp);
	new->next = (*all_ways);
	(*all_ways) = new;
}

void		del_same(t_route **all_ways)
{
	t_route	*tmp;
	t_route	*find;
	t_route	*start;

	start = *all_ways;
	tmp = *all_ways;
	while (tmp)
	{
		find = tmp->next;
		if (after_point(&tmp, find))
			del_one_way(&tmp);
		if (before_point(&tmp, start))
			del_one_way(&tmp);
		tmp = tmp->next;
	}
}

int			after_point(t_route **tmp, t_route *find)
{
	while (find)
	{
		if (!same_way(*tmp, find))
			return (1);
		find = find->next;
	}
	return (0);
}
