/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_route1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:30:03 by klee              #+#    #+#             */
/*   Updated: 2018/03/20 15:30:05 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void		ways_with_end(t_route **all_ways, int end)
{
	t_route		*tmp;
	t_route		*new;
	char		*buf;
	char		*end_char;

	tmp = *all_ways;
	new = NULL;
	end_char = ft_itoa(end);
	while (tmp)
	{
		if (cmp_way(tmp->route, end_char))
		{
			buf = without_tail(tmp->route, end_char);
			add_way(&new, &buf);
		}
		tmp = tmp->next;
	}
	tmp = *all_ways;
	*all_ways = new;
	clear_way_list(&tmp);
	free(end_char);
	del_same(all_ways);
	correction_ways(all_ways);
}

int			cmp_way(char *route, char *end_char)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(route, '-');
	while (tmp[i])
	{
		if (!ft_strcmp(tmp[i], end_char))
		{
			clear_res_split(&tmp);
			return (1);
		}
		i++;
	}
	clear_res_split(&tmp);
	return (0);
}

void		del_one_way(t_route **find)
{
	ft_strdel(&((*find)->route));
}

void		correction_ways(t_route **all_ways)
{
	t_route		*tmp;
	t_route		*new;
	char		*buf;

	tmp = *all_ways;
	new = NULL;
	while (tmp)
	{
		if (tmp->route)
		{
			buf = ft_strdup(tmp->route);
			add_way(&new, &buf);
		}
		tmp = tmp->next;
	}
	tmp = *all_ways;
	*all_ways = new;
	clear_way_list(&tmp);
}

void		clear_way_list(t_route **all_ways)
{
	t_route	*tmp;

	while (*all_ways)
	{
		tmp = *all_ways;
		*all_ways = (*all_ways)->next;
		ft_strdel(&(tmp->route));
		free(tmp);
	}
}
