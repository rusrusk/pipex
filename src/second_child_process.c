/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_child_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:29:41 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/15 16:01:33 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	second_process(t_data *data, char **argv, char **env)
{
	data->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->outfile < 0)
		prompt_system_error();
	if (dup2(data->pipefd[0], STDIN_FILENO) == ERROR)
		prompt_system_error();
	close(data->pipefd[1]);
	if (dup2(data->outfile, STDOUT_FILENO) == ERROR)
		prompt_system_error();
	close(data->outfile);
	data->command = ft_split(argv[3], 32);
	if (!(set_command_path(*data->command, env)))
		error_handle(COMMAND_ERROR);
	data->proper_path_to_cmd = set_command_path(*data->command, env);
	if (!(execve(data->proper_path_to_cmd, data->command, env) == -1))
		prompt_system_error();
	ft_free(data->command);
	free(data->proper_path_to_cmd);
}
