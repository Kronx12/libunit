/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:46:56 by gbaud             #+#    #+#             */
/*   Updated: 2022/05/25 19:06:04 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	libunit_clear(t_libunit *libunit)
{
	t_libunit *next;

	while (libunit)
	{
		next = libunit->next;
		free(libunit->name);
		free(libunit);
		libunit = next;
	}
}
