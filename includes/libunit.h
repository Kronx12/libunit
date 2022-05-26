/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:33:05 by gbaud             #+#    #+#             */
/*   Updated: 2022/05/26 11:31:36 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>

typedef struct			s_libunit
{
	char				*name;
	int					(*f)(void);
	struct s_libunit	*next;
}						t_libunit;

int					libunit_strlen(char *str);
char				*libunit_strdup(char *str);
t_libunit			*libunit_init(char *name, int (*f)(void));
void				libunit_clear(t_libunit *libunit);
int					libunit_load_test(t_libunit **libunit, char *name, int (*f)(void));
int					libunit_launch_tests(t_libunit **libunit);

#endif //!GLOBAL_H