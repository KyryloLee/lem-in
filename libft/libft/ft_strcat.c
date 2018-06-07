/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:37:42 by klee              #+#    #+#             */
/*   Updated: 2017/11/13 13:34:11 by klee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (s1[c])
		c++;
	while (s2[i])
		s1[c++] = s2[i++];
	s1[c++] = '\0';
	return (s1);
}
