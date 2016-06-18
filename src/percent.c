/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 19:24:38 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/18 12:50:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

int				percent
	(t_parse_result *p, t_vect **v)
{
	(void)p;
	return (vect_memset(v, '%', 1, 0));
}
