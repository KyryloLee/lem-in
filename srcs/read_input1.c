/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:38:22 by klee              #+#    #+#             */
/*   Updated: 2018/03/20 15:38:24 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			wrong_number(void)
{
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	ft_printf("🌻 🌻          ERROR          🌻 🌻\n");
	ft_printf("🌻 🌻  WRONG NUMBER OF ANTS!!!🌻 🌻\n");
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	return (-1);
}

int			empty_file(void)
{
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	ft_printf("🌻 🌻        ERROR          🌻 🌻\n");
	ft_printf("🌻 🌻     EMPTY FILE!!!     🌻 🌻\n");
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	return (-1);
}

int			wrong_input_rooms(void)
{
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	ft_printf("🌻 🌻         ERROR         🌻 🌻\n");
	ft_printf("🌻 🌻  WRONG INPUT ROOMS!!! 🌻 🌻\n");
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	return (-1);
}

int			wrong_input_links(void)
{
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	ft_printf("🌻 🌻         ERROR         🌻 🌻\n");
	ft_printf("🌻 🌻  EMPTY INPUT LINKS!!! 🌻 🌻\n");
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	return (-1);
}

int			same_rooms(t_rooms **list_rooms, char *line2, int index)
{
	t_rooms			*tmp;
	char			**split;

	tmp = *list_rooms;
	split = ft_strsplit(line2, ' ');
	if (str_is_numb(split[1]) || str_is_numb(split[2]))
		return (-1);
	while (tmp)
	{
		if ((!ft_strcmp(split[1], tmp->y) && !ft_strcmp(split[2], tmp->x)) ||\
		(index != 1 && tmp->pos == index) || (!ft_strcmp(split[0], tmp->name)))
		{
			clear_res_split(&split);
			return (-1);
		}
		tmp = tmp->next;
	}
	clear_res_split(&split);
	return (0);
}
