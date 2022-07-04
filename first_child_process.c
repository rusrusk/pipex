/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:00:08 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/04 18:18:43 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void first_process (int *pipefd, char **argv, char **env)
{
	char	**command;
	char	*proper_path_to_cmd = NULL;
	int 	fd[2];

	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
	{
		error_handle("Unable to read the file");
		exit(1);	
	}
	close(pipefd[0]);
	
	dup2(fd[0], STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	command = ft_split(argv[2], 32);
	if (!(command))
		error_handle("error!");
	if (!(proper_path_to_cmd == set_command_path(*command, env)))
		error_handle("error!");
	if (!(execve(proper_path_to_cmd, command, env) == -1))
	{
		error_handle("execve system error!");
	}
	ft_free(command);
	free(proper_path_to_cmd);
}