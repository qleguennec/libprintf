/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:30:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/04 14:20:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_CONVERSIONS_H
# define LIBPRINTF_CONVERSIONS_H

#include <libprintf_alphabets.h>
#include <stdint.h>

typedef uintmax_t	t_arg;

typedef struct		s_conv_spec
{
	char			name;
	t_arg			arg;
	t_list			*(* conv_f)(struct s_conv_spec *);
	unsigned int	neg : 1;
	size_t			size;
	unsigned int	base : 3;
	unsigned int	valid_attrs : 5;
	unsigned int	attrs : 5;
}					t_conv_spec;

t_list				*i_conv
	(t_conv_spec *self);
t_list				*s_conv
	(t_conv_spec *self);

static t_conv_spec	convs_arr[] =
{
	{'d', 0, &i_conv, 0, sizeof(int), BASE10, 30, 0},
	{'i', 0, &i_conv, 0, sizeof(int), BASE10, 30, 0},
	{'o', 0, &i_conv, 0, sizeof(int), BASE8, 3, 0},
	{'x', 0, &i_conv, 0, sizeof(int), BASE16LOW, 3, 0},
	{'X', 0, &i_conv, 0, sizeof(int), BASE16UP, 3, 0},
	{'s', 0, &s_conv, 0, sizeof(char *), BASE16UP, 0, 0},
};

#endif
