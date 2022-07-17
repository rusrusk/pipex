/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:23:27 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/17 15:03:52 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#ifndef IS_BONUS

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pipefd[2];

	error_info(argc);
	if (pipe(pipefd) < 0)
	{
		error_handle("error while piping ------> 3\n");
	}
	pipex(fd, pipefd, argv, envp);
	return (0);
}

#endif
