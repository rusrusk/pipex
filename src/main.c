/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:23:27 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/15 16:01:24 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

#ifndef IS_BONUS

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	error_info(argc);
	if (pipe(data.pipefd) < 0)
		prompt_system_error();
	if (pipex(&data, argv, envp) == ERROR)
		return (ERROR);
	return (0);
}

#endif
