/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:58:18 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/15 16:00:12 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	prompt_system_error(void)
{
	printf("Error number is: %d\n", errno);
	printf("Error description is : %s\n", strerror(errno));
	return (ERROR);
}

void	prompt_error_message(void)
{
	ft_putstr_fd("\033[31mERROR: Bad argument\n\e[0m", 2);
	exit(SUCCESS);
}
