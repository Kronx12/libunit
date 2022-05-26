/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_load_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:46:56 by gbaud             #+#    #+#             */
/*   Updated: 2022/05/24 20:49:50 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	libunit_load_test(t_libunit **libunit, char *name, int (*f)(void))
{
	t_libunit *copy;
	
	if (!*libunit)
	{
		if (!(*libunit = libunit_init(name, f)))
		{
			libunit_clear(*libunit);
			*libunit = NULL;
			return (1);
		}
	}
	else
	{
		copy = *libunit;
		while (copy->next)
			copy = copy->next;
		if (!(copy->next = libunit_init(name, f)))
		{
			libunit_clear(*libunit);
			*libunit = NULL;
			return (1);
		}
	}
	return (0);
}
