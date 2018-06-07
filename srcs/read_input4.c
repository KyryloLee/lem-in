/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:41:25 by klee              #+#    #+#             */
/*   Updated: 2018/03/20 15:41:27 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

char		*beg_recursio(char *s, char c)
{
	if (*s == 0)
		return (0);
	if (*s == c)
		s = beg_recursio(s + 1, c);
	return (s);
}

int			nmb_wrd(char *copy, char c)
{
	int		count;

	count = 0;
	while (copy)
	{
		copy = beg_recursio(copy, c);
		if (copy)
		{
			count++;
			copy = ft_strchr(copy, c);
		}
	}
	return (count);
}

int			valid_room(char *line, t_rooms **list_rooms)
{
	int		i;

	i = 0;
	if (!ft_strcmp(line, "##start"))
	{
		if (if_end_or_start(list_rooms, 0) < 0)
			return (-1);
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (if_end_or_start(list_rooms, 2) < 0)
			return (-1);
	}
	else
	{
		i = add_new_rooms(list_rooms, line);
		if (i < 0)
			return (-1);
		else if (i == 0)
			return (0);
		else if (i == 1)
			return (1);
	}
	return (1);
}

int			make_new_room(t_rooms **list_rooms, char *line2, int index)
{
	t_rooms		*add;
	char		**res_split;

	res_split = NULL;
	add = NULL;
	if (nmb_wrd(line2, ' ') != 3 || ft_strnstr(line2, "L", 1) ||\
		(same_rooms(list_rooms, line2, index)))
		return (-1);
	else
	{
		ft_printf("%s\n", line2);
		add = (t_rooms*)malloc(sizeof(t_rooms));
		res_split = ft_strsplit(line2, ' ');
		add->name = ft_strdup(res_split[0]);
		add->y = ft_strdup(res_split[1]);
		add->x = ft_strdup(res_split[2]);
		add->pos = index;
		add->next = (*list_rooms);
		(*list_rooms) = add;
		clear_res_split(&res_split);
	}
	return (0);
}

int			if_valid_minus(char **line, t_rooms **list_rooms, t_input **res)
{
	free(*line);
	(*res)->rooms = *list_rooms;
	return (wrong_input_rooms());
}
