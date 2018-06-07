/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_route3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:30:42 by klee              #+#    #+#             */
/*   Updated: 2018/03/20 15:30:45 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void		display_moves(char **tmp, unsigned int index)
{
	unsigned int		i[6];

	i[0] = 1;
	i[3] = 0;
	i[4] = 0;
	while (tmp[i[4]])
		i[4]++;
	i[4]--;
	i[5] = index + i[4] - 1;
	while (i[0] <= i[5])
	{
		i[3] < i[4] ? i[3]++ : 1 - 1;
		i[1] = i[3];
		i[2] = i[0] > i[4] ? i[0] - i[4] + 1 : 1;
		while (i[1] > 0)
		{
			if (i[2] <= index)
				ft_printf("L%d-%s ", i[2], tmp[i[1]]);
			i[1]--;
			i[2]++;
		}
		i[4] > 1 ? ft_printf("\n") : 1 - 1;
		i[0]++;
	}
}

char		*find_name(t_rooms *n_room, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		n_room = n_room->next;
		i++;
	}
	return (n_room->name);
}

char		**change_name_of_room(t_route **all_way, t_input *res)
{
	char		**tmp;
	char		*str;
	t_rooms		*n_room;
	int			i[2];

	i[0] = 0;
	tmp = ft_strsplit((*all_way)->route, '-');
	n_room = res->rooms;
	while (tmp[i[0]])
	{
		str = tmp[i[0]];
		i[1] = ft_atoi(tmp[i[0]]);
		tmp[i[0]] = ft_strdup(find_name(n_room, i[1]));
		free(str);
		i[0]++;
	}
	return (tmp);
}

void		move_ants(t_route *all_way, t_input *res)
{
	int		i;
	int		c;
	char	**tmp;

	if (!all_way)
		not_enough_data();
	if (all_way && res->numb > 0)
	{
		c = 0;
		i = res->numb;
		tmp = change_name_of_room(&all_way, res);
		while (tmp[c])
		{
			if (tmp[c + 1])
				ft_printf("[%s]⏩ ", tmp[c++]);
			else
				ft_printf("[%s]\n", tmp[c++]);
		}
		display_moves(tmp, i);
		clear_res_split(&tmp);
	}
	else
		ft_printf("\n");
}

int			check_the_way(t_route *tmp, t_route *start)
{
	if (!before_point_way(tmp, start) || !after_point_way(tmp, tmp->next))
		return (0);
	return (1);
}
