/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:56:55 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/15 16:00:16 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(t_source *source, int argc, char *limiter)
{
	if (argc < 6)
		prompt_error_message();
	if (pipe(source->pipefd) == ERROR)
		prompt_system_error();
	source->pid = fork();
	if (source->pid == ERROR)
		prompt_system_error();
	if (source->pid == 0)
	{
		close(source->infile);
		while (get_next_line(&source->line))
		{
			if (ft_strncmp(source->line, limiter, ft_strlen(limiter)) == SUCCESS)
				exit(SUCCESS);
			write(source->outfile, source->line, ft_strlen(source->line));
		}
	}
	else
	{
		close(source->outfile);
		dup2(source->infile, STDIN_FILENO);
		wait(NULL);
	}
}
