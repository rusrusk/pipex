/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:19:56 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/17 15:53:44 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_info(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("invalid number of arguments!!!\n", STDOUT_FILENO);
		exit(1);
	}
}

void	error_handle(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}
