/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:06:25 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/05 11:37:21 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int *fd, int *pipefd, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
	{
		error_handle("error while forking ----> 1\n");
	}
	if (pid1 == 0)
	{
		first_process(fd, pipefd, argv, envp);
	}
	pid2 = fork();
	if (pid2 < 0)
	{
		error_handle("error while forking ----> 2\n");
	}
	if (pid2 == 0)
	{
		waitpid(pid1, NULL, 0);
		second_process(fd, pipefd, argv, envp);
	}
	close (pipefd[0]);
	close (pipefd[1]);
	waitpid(pid2, NULL, 0);
}

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
	// int fd3 = open("test.txt", O_WRONLY);
	// printf("last open fd --->%d\n", fd3);
	// close(fd3);
	return (0);
}

/*
int	main(int argc, char **argv, char **envp)
{
	char	*path;

	error_info(argc);
	if (argc == 2)
	{
	path = set_command_path(argv[1], envp);
	printf("%s\n", path);
	}
	// while (path[i])
	// {
	// 	printf("%s\n", path[i]);
	// }
}
*/