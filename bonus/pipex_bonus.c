/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:59:04 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/15 15:59:53 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_source	source;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == SUCCESS)
		{
			source.idx = 3;
			source.outfile = open_file(argv[argc - 1], 0);
			here_doc(&source, argv[2], argc);
		}
		else
		{
			source.idx = 2;
			source.outfile = open_file(argv[argc - 1], 1);
			source.infile = open_file(argv[1], 2);
			dup2(source.infile, STDIN_FILENO);
		}
		while (source.idx < argc - 2)
			child(&source, argv[source.idx++], envp);
		dup2(source.outfile, STDOUT_FILENO);
		execute(&source, argv[argc - 2], envp);
	}
	prompt_error_message();
}
