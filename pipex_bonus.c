/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:27:00 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/17 17:08:17 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_bonus(char *command, char **env)
{
	char	**split_cmd;
	char	*proper_path_to_cmd;

	split_cmd = ft_split(command, 32);
	proper_path_to_cmd = set_command_path(*split_cmd, env);
	if (execve(proper_path_to_cmd, split_cmd, env) == -1)
	{
		error_handle("error while using env var in bonus!");
		ft_free(split_cmd);
		free(proper_path_to_cmd);
		exit(0);
	}
}

static void	pipex_bonus(char *command, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		error_handle("Error in pipe");
	pid = fork();
	if (pid < 0)
	{
		error_handle("ERROR");
	}
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		child_bonus(command, env);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

static void	handling_dups(int argc, char **argv)
{
	int	fdin;
	int	fdout;

	fdin = open(argv[1], O_RDONLY);
	if (fdin < 0)
		error_handle("error while reading a file in bonus");
	fdout = open(argv[argc - 1], O_RDONLY | O_WRONLY | O_APPEND);
	if (fdout < 0)
		error_handle("error while writing to file in bonus");
	dup2(fdin, STDIN_FILENO);
	close(fdin);
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
}

void	check_commands(int argc, char **argv, char **env)
{
	char	*path;
	char	**split_args;
	int		i;

	i = 2;
	while (i <= (argc - 2))
	{
		split_args = ft_split(argv[i], 32);
		path = set_command_path(*split_args, env);
		if (!path)
		{
			free(path);
			error_handle("invalid command!");
			ft_free(split_args);
			exit(0);
		}
		else
		{
			ft_free(split_args);
			free(path);
		}
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	int	i;

	if (argc < 5)
		error_handle("invalid number of arguments for bonus part!!!");
	check_commands(argc, argv, env);
	handling_dups(argc, argv);
	i = 2;
	while (i < (argc - 2))
	{
		pipex_bonus(argv[i++], env);
	}
	child_bonus(argv[i], env);
}
