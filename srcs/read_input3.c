/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:38:46 by klee              #+#    #+#             */
/*   Updated: 2018/03/20 15:38:47 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			add_new_rooms(t_rooms **list_rooms, char *line)
{
	char **tmp_res_split;

	tmp_res_split = NULL;
	if (ft_strnstr(line, "#", 1))
	{
		ft_printf("%s\n", line);
		return (1);
	}
	if (nmb_wrd(line, ' ') != 3)
	{
		if (nmb_wrd(line, ' ') == 1)
		{
			if (right_room(line, list_rooms))
				return (0);
			else
				return (-1);
		}
		else
			return (-1);
	}
	else
		return (make_new_room(list_rooms, line, 1) < 0 ? -1 : 1);
	return (1);
}

int			valid_links(char *line, t_rooms **list_rooms, t_input **res)
{
	if ((*res)->links == NULL)
	{
		(*res)->links = new_links(0, list_rooms);
		return (put_link(line, list_rooms, res));
	}
	return (0);
}

int			how_much_rooms(t_rooms *list_rooms)
{
	int		numb;

	numb = 0;
	while (list_rooms)
	{
		numb++;
		list_rooms = list_rooms->next;
	}
	return (numb);
}

void		clear_res_split(char ***tmp)
{
	int		i;

	i = 0;
	while ((*tmp)[i])
		free((*tmp)[i++]);
	free((*tmp));
}

int			if_end_or_start(t_rooms **list_rooms, int index)
{
	char	*line2;

	line2 = NULL;
	if (index == 0)
		ft_printf("##start\n");
	if (index == 2)
		ft_printf("##end\n");
	get_next_line(0, &line2);
	if (make_new_room(list_rooms, line2, index) < 0)
	{
		free(line2);
		return (-1);
	}
	free(line2);
	return (0);
}
