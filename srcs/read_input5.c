/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:27:00 by klee              #+#    #+#             */
/*   Updated: 2018/03/21 13:27:03 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int			not_enough_data(void)
{
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	ft_printf("🌻 🌻          ERROR          🌻 🌻\n");
	ft_printf("🌻 🌻    NOT ENOUGH DATA!!!   🌻 🌻\n");
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	return (-1);
}

int			no_start_or_end(void)
{
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	ft_printf("🌻 🌻          ERROR          🌻 🌻\n");
	ft_printf("🌻 🌻    NO START OR END!!!   🌻 🌻\n");
	ft_printf("🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻 🌻\n");
	return (-1);
}
