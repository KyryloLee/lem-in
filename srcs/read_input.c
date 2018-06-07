/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:31:52 by klee              #+#    #+#             */
/*   Updated: 2018/02/23 14:31:54 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			read_input(t_input **res)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (i != 1)
	{
		if (get_next_line(0, &line) == 0)
			return (empty_file());
		i = number_of_ants(res, &line);
		if (i < 0)
			return (wrong_number());
		ft_strdel(&line);
	}
	if (find_rooms(res))
		return (-1);
	ft_printf("\n");
	return (0);
}

int			str_is_numb(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (1);
	}
	return (0);
}

int			number_of_ants(t_input **data, char **line)
{
	if (!str_is_numb(*line))
	{
		ft_printf("%s\n", *line);
		(*data)->numb = ft_atoi(*line);
		return (1);
	}
	else if (ft_strnstr(*line, "#", 1))
	{
		if (ft_strnstr(*line, "##", 2))
		{
			free(*line);
			return (-1);
		}
		ft_printf("%s\n", line);
	}
	else
	{
		free(*line);
		return (-1);
	}
	return (0);
}

int			find_rooms(t_input **res)
{
	int			i;
	char		*line;
	t_rooms		*list_rooms;

	line = NULL;
	list_rooms = NULL;
	while (get_next_line(0, &line) > 0)
	{
		i = valid_room(line, &list_rooms);
		if (i < 0)
		{
			(*res)->rooms = list_rooms;
			return (if_valid_minus(&line, &list_rooms, res));
		}
		if (i == 0)
			if (valid_links(line, &list_rooms, res))
			{
				(*res)->rooms = list_rooms;
				free(line);
				return (0);
			}
		free(line);
	}
	(*res)->rooms = list_rooms;
	return (0);
}
