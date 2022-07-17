/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:00:08 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/17 16:04:28 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_process(int *fd, int *pipefd, char **argv, char **env)
{
	char	**command;
	char	*proper_path_to_cmd;

	fd[0] = open(argv[1], O_RDONLY, 0644);
	if (fd[0] < 0)
	{
		error_handle("Unable to read the file");
	}
	close(pipefd[0]);
	dup2(fd[0], STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	command = ft_split(argv[2], 32);
	if (!set_command_path(*command, env))
		error_handle("invalid command <---- 4");
	proper_path_to_cmd = set_command_path(*command, env);
	if (execve(proper_path_to_cmd, command, env) == -1)
		error_handle("execve system error! <---- 5");
	ft_free(command);
	free(proper_path_to_cmd);
}
