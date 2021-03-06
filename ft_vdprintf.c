/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:31:34 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 14:06:44 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf_intern.h"
#include <unistd.h>

int				ft_vdprintf
	(int fd, const char *format, va_list ap)
{
	t_vect		*v;
	size_t		len;

	v = get_result(format, ap);
	if (!v)
		return (-1);
	len = write(fd, v->data, v->used);
	vect_del(v);
	return (len <= INT_MAX ? len : -1);
}
