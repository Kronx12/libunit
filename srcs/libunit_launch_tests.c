/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_launch_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:46:56 by gbaud             #+#    #+#             */
/*   Updated: 2022/05/26 12:33:22 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	libunit_launch_tests(t_libunit **libunit)
{
	pid_t pid;
	int sig;
	int status;
	t_libunit *copy;

	copy = *libunit;
	while (copy)
	{
		pid = fork();
		if (!pid)
			exit(copy->f());
		else
		{
			wait(&status);
			write(1, "\033[37;1mRunning test [\033[36;1m", 29);
			write(1, copy->name, libunit_strlen(copy->name));
			write(1, "\033[37;1m]: \033[0m", 15);
			if (WIFSIGNALED(status))
			{
				sig = WTERMSIG(status);
				if (sig == SIGSEGV)
					write(1, "\033[31;1m[SEGV]\033[0m", 18);
				else if (sig == SIGABRT)
					write(1, "\033[31;1m[ABRT]\033[0m", 18);
				else if (sig == SIGBUS)
					write(1, "\033[31;1m[BUS ERROR]\033[0m", 23);
				else if (sig == SIGPIPE)
					write(1, "\033[31;1m[BROKEN PIPE]\033[0m", 25);
				else if (sig == SIGILL)
					write(1, "\033[31;1m[SIGKILL]\033[0m", 21);
				else
					write(1, "\033[31;1m[UNSUPPORTED SIGNAL]\033[0m", 32);
			}
			else
				write(1, WEXITSTATUS(status) ? "\033[31;1m[KO]\033[0m" : "\033[32;1m[OK]\033[0m", 16);
			write(1, "\n", 1);
		}
		copy = copy->next;
	}
	libunit_clear(*libunit);
	*libunit = NULL;
	return (0); // Ou -1 en cas d'erreur
}
