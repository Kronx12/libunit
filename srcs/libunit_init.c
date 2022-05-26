/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:46:56 by gbaud             #+#    #+#             */
/*   Updated: 2022/05/24 20:50:14 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_libunit   *libunit_init(char *name, int (*f)(void))
{
	t_libunit *new;

	if (!(new = malloc(sizeof(t_libunit))))
		return (NULL);
	if (!(new->name = libunit_strdup(name)))
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	new->f = f;
	return (new);
}
