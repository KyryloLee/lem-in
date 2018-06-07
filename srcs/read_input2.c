/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:38:36 by klee              #+#    #+#             */
/*   Updated: 2018/03/20 15:38:39 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void		put_link_list(char *line, t_rooms **list_rooms, t_input **res)
{
	int			i[2];
	t_rooms		*tmp;
	t_rooms		*tmp1;

	i[0] = 0;
	tmp = *list_rooms;
	ft_printf("%s\n", line);
	while (tmp)
	{
		tmp1 = tmp->next;
		i[1] = i[0] + 1;
		while (tmp1)
		{
			if (both_rooms_and_defis(line, tmp->name, tmp1->name))
			{
				(*res)->links[i[0]][i[1]] = '1';
				(*res)->links[i[1]][i[0]] = '1';
				return ;
			}
			tmp1 = tmp1->next;
			i[1]++;
		}
		tmp = tmp->next;
		i[0]++;
	}
}

int			right_room(char *line, t_rooms **list_rooms)
{
	t_rooms	*start;
	t_rooms	*start1;

	start = (*list_rooms);
	if (!ft_strncmp(line, "#", 1) && ft_strcmp(line, "##start") &&\
			ft_strcmp(line, "##end"))
	{
		ft_printf("%s\n", line);
		return (2);
	}
	while (start)
	{
		start1 = start->next;
		while (start1)
		{
			if (both_rooms_and_defis(line, start->name, start1->name))
				return (1);
			start1 = start1->next;
		}
		start = start->next;
	}
	return (0);
}

int			both_rooms_and_defis(char *line, char *name1, char *name2)
{
	size_t		sum_name;
	size_t		len_line;

	sum_name = ft_strlen(name1) + ft_strlen(name2) + 1;
	len_line = ft_strlen(line);
	if (ft_strstr(line, name1) && ft_strstr(line, name2))
		if (len_line == sum_name)
			return (1);
	return (0);
}

char		**new_links(int numb_rooms, t_rooms **list_rooms)
{
	char	**links;
	int		i;

	i = 0;
	numb_rooms = how_much_rooms((*list_rooms));
	links = (char**)malloc(sizeof(char*) * (numb_rooms + 1));
	while (i < numb_rooms)
	{
		links[i] = ft_strnew(numb_rooms);
		ft_memset(links[i], '0', numb_rooms);
		i++;
	}
	links[i] = 0;
	return (links);
}

int			put_link(char *line, t_rooms **list_rooms, t_input **res)
{
	char	*line2;
	int		i;

	line2 = NULL;
	if (find_start_or_end(*list_rooms, 0) < 0\
	|| find_start_or_end(*list_rooms, 2) < 0)
		return (no_start_or_end());
	if (right_room(line, list_rooms) == 1)
		put_link_list(line, list_rooms, res);
	else
		return (wrong_input_links());
	while (get_next_line(0, &line2))
	{
		i = right_room(line2, list_rooms);
		if (i == 1)
			put_link_list(line2, list_rooms, res);
		else if (i == 0)
		{
			free(line2);
			return (1);
		}
		free(line2);
	}
	return (0);
}
