/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:19:56 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/15 16:00:52 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_info(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd(INPUT_ERROR, STDOUT_FILENO);
		exit(1);
	}
}

void	error_handle(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

int	prompt_system_error(void)
{
	printf("Error number is: %d\n", errno);
	printf("Error description is : %s\n", strerror(errno));
	return (ERROR);
}
