/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:06:25 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/17 14:28:36 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int *fd, int *pipefd, char **argv, char **envp)
{
	pid_t	child1;
	pid_t	child2;

	child1 = fork();
	if (child1 < 0)
	{
		error_handle("error while forking ----> 1\n");
	}
	if (child1 == 0)
	{
		first_process(fd, pipefd, argv, envp);
	}
	waitpid(child1, NULL, 0);
	child2 = fork();
	if (child2 < 0)
	{
		error_handle("error while forking ----> 2\n");
	}
	if (child2 == 0)
	{
		second_process(fd, pipefd, argv, envp);
	}
	close (pipefd[0]);
	close (pipefd[1]);
	waitpid(child2, NULL, 0);
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

/*
	int fd3 = open("test.txt", O_WRONLY);
	printf("last open fd --->%d\n", fd3);
	close(fd3);
*/