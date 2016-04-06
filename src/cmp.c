/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:09:59 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 20:37:19 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

int			cmp
	(void *a, void *b)
{
	char	*s1;
	char	*s2;

	s1 = (char *)a;
	s2 = (char *)b;
	return (ft_strcmp(s1, s2));
}
