/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_files_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:56:14 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/15 16:00:22 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	open_file(char *argv, t_source *source)
{
	int	file;

	file = 0;
	if (source->idx == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (source->idx == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (source->idx == 2)
		file = open (argv, O_RDONLY, 0777);
	if (file == ERROR)
		prompt_system_error();
	return (file);
}