/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:06:25 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/15 16:01:29 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	pipex(t_data *data, char **argv, char **envp)
{
	data->child1 = fork();
	if (data->child1 < 0)
		prompt_system_error();
	if (data->child1 == 0)
		first_process(data, argv, envp);
	data->child2 = fork();
	if (data->child2 < 0)
		prompt_system_error();
	if (data->child2 == 0)
		second_process(data, argv, envp);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	waitpid(data->child1, NULL, 0);
	waitpid(data->child2, NULL, 0);
	return (SUCCESS);
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