/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:14:44 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/17 15:46:08 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_path_var(char **str)
{
	int	i;

	i = 0;
	while (ft_strnstr(str[i], "PATH=", 5) == 0)
	{
		i++;
	}
	return (i);
}

char	**path_to_env( char **envp)
{
	int		i;
	char	**path_variations;

	i = 0;
	i = find_path_var(envp);
	path_variations = ft_split(envp[i] + 5, ':');
	return (path_variations);
}

char	*set_command_path(char *command, char **env)
{
	char	**potential_path;
	char	*find_slash;
	char	*command_path_with_slash;
	int		i;

	i = 0;
	potential_path = path_to_env(env);
	while (potential_path[i])
	{
		find_slash = ft_strjoin(potential_path[i], "/");
		command_path_with_slash = ft_strjoin(find_slash, command);
		free(find_slash);
		if (access(command_path_with_slash, F_OK) == 0)
		{
			return (command_path_with_slash);
		}
		free(command_path_with_slash);
		i++;
	}
	ft_free(potential_path);
	return (NULL);
}
