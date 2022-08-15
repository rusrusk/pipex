/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:00:08 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/15 16:01:16 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_process(t_data *data, char **argv, char **env)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == ERROR)
	{
		prompt_system_error();
	}
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[0]);
	dup2(data->infile, STDIN_FILENO);
	close(data->infile);
	data->command = ft_split(argv[2], 32);
	if (!set_command_path(*data->command, env))
		error_handle(COMMAND_ERROR);
	data->proper_path_to_cmd = set_command_path(*data->command, env);
	if (execve(data->proper_path_to_cmd, data->command, env) == -1)
		prompt_system_error();
	ft_free(data->command);
	free(data->proper_path_to_cmd);
}
