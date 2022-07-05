/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:29:41 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/05 11:45:43 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_process(int *fd, int *pipefd, char **argv, char **env)
{
	char **command;
	char *proper_path_to_cmd;
	// int	fd[2];
	// command = NULL;
	fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd[1] < 0)
		error_handle("Error occured while writing to outfile\n");
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	// if (!command)
	// 	error_handle("error3");
	command = ft_split(argv[3], 32);
	if (!(set_command_path(*command, env)))
		error_handle("error4");
	proper_path_to_cmd = set_command_path(*command, env);
	if (!(execve(proper_path_to_cmd, command, env) == -1))
		error_handle("error5");
	ft_free(command);
	free(proper_path_to_cmd);
	// return (fd);
}
