/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 11:07:10 by klee              #+#    #+#             */
/*   Updated: 2018/02/26 11:07:18 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

t_input		*make_struct(void)
{
	t_input *strct;

	strct = malloc(sizeof(t_input));
	strct->rooms = NULL;
	strct->links = NULL;
	return (strct);
}

void		clean_links(char ***links)
{
	int		i;

	i = 0;
	if (*links)
	{
		while ((*links)[i])
			ft_strdel(&(*links)[i++]);
		free(*links);
	}
	(*links) = NULL;
}

void		clear_struct(t_input **res)
{
	free((*res));
}

void		clean_rooms(t_rooms **show_rooms)
{
	t_rooms	*tmp;

	tmp = NULL;
	while (*show_rooms)
	{
		tmp = *show_rooms;
		*show_rooms = (*show_rooms)->next;
		free(tmp->name);
		free(tmp->x);
		free(tmp->y);
		free(tmp);
	}
}

int			main(void)
{
	t_input			*res;
	t_rooms			*show_rooms;
	char			**show_links;
	int				i;

	i = 0;
	res = make_struct();
	if (!read_input(&res))
		if (build_route(res))
			;
	show_rooms = res->rooms;
	show_links = res->links;
	clean_rooms(&(res)->rooms);
	clean_links(&show_links);
	clear_struct(&res);
	return (0);
}
