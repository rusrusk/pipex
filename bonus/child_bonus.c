/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:42:36 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/15 16:24:11 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	execute(t_source *source, char *argv, char **env)
{
	int	i;

	i = -1;
	source->command = ft_split(argv, 32);
	source->command_path = set_command_path(*source->command, env);
	if (!source->command_path)
	{
		while (source->command[++i])
			free(source->command[i]);
		free(source->command);
		prompt_system_error();
	}
	if (execve(source->command_path, source->command, env) == ERROR)
		prompt_system_error();
}

void	child(t_source *source, char *argv, char **env)
{
	if (pipe(source->pipefd) == ERROR)
		prompt_system_error();
	source->pid = fork();
	if (source->pid == ERROR)
		prompt_system_error();
	if (source->pid == 0)
	{
		close(source->infile);
		if (dup2(source->outfile, STDOUT_FILENO) == ERROR)
			prompt_system_error();
		execute(source, argv, env);
	}
	else
	{
		close(source->outfile);
		if (dup2(source->infile, STDIN_FILENO) == ERROR)
			prompt_system_error();
		waitpid(source->pid, NULL, 0);
	}
}
