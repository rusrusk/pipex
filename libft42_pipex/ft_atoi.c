/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:52:59 by rkultaev          #+#    #+#             */
/*   Updated: 2022/05/10 01:10:49 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	conversion(const char *str, int plus_minus, int i)
{
	long int	nb;

	nb = 0;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		if (nb > 2147483648 && plus_minus == -1)
			return (0);
		if (nb > 2147483647 && plus_minus == 1)
			return (-1);
			nb = nb * 10 + str[i] - 48;
			i++;
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	int				plus_minus;
	int				i;
	long int		value;

	value = 0;
	i = 0;
	plus_minus = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
				plus_minus = -1;
		}
		i++;
	}
	value = conversion(str, plus_minus, i);
	return (value * plus_minus);
}
