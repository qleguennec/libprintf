/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:52:26 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 18:57:46 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>
#include <limits.h>

int			main(void)
{
	int	i = 1;
	ft_printf("call %d, %x\n", i++, 0);
	ft_printf("call %d, %x\n", i++, 123);
	ft_printf("call %d, %d\n", i++, INT_MAX);
}
