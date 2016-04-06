/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 16:22:41 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static t_arg			get_mask
	(size_t size)
{
	t_arg				mask;
	size_t				i;

	i = 0;
	mask = 0;
	while (i < size * 8)
		mask |= (t_arg)1 << i++;
	return (mask);
}

static t_arg		abs_value
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	t_arg				ret;
	t_arg				mask;

	ret = (t_arg)ctxt->arg;
	mask = get_mask(self->size);
	if ((PLUS_MASK & self->valid_attrs)
		&& (ret >> (8 * self->size - 1)))
	{
		ret = mask & (~ ret) + 1;
		self->neg = 1;
	}
	return (ret);
}

t_list					*i_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	t_list				*ret;
	size_t				len;
	size_t				base;
	t_arg				y;

	if (!ctxt->arg)
		return (null_case(self));
	base = ft_strlen(alphabets[self->base]);
	y = abs_value(self, ctxt);
	len = ft_max(ctxt->prec, digits_nb(y, base));
	if (!(ret = ft_lstnew(NULL, len)))
		return (NULL);
	while (len)
	{
		(((char *)ret->content)[--len]) =
			*(alphabets[self->base] + y % base);
		y /= base;
		if (y && y < base)
		{
			(((char *)ret->content)[--len]) =
				*(alphabets[self->base] + y % base);
			y = 0;
		}
	}
	return (ret);
}
