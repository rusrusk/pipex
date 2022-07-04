/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:14:44 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/04 18:32:06 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int is_include_path(char *string)
// {
// 	return ft_strnstr(string, "PATH=", 5);
// }


int	find_path_var (char **str)
{
	int i;
	i = 0;
	while (ft_strnstr(str[i], "PATH=", 5) == 0)
	{
		i++;
	}
	return (i);
}

char **path_to_env( char **envp)
{
		int	i;
		// char	*road_path;
		char **path_variations;

		i = 0;
		i = find_path_var(envp);
		// road_path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		path_variations = ft_split(envp[i] + 5, ':');
		// free(road_path);
		// printf("Nice");
		return (path_variations);
}

char	*set_command_path(char *command, char **env)
{
	char	**potential_path;
	char	*find_slash;
	char	*command_path_with_slash;
	int		i;

	i = 0;
	// if (!path_to_env)
	// 	error_handle("Error!");
	potential_path = path_to_env(env);
	while (potential_path[i])
	{
		find_slash = ft_strjoin(potential_path[i], "/");
		command_path_with_slash = ft_strjoin(find_slash, command);
		free(find_slash);
		if (access(command_path_with_slash, F_OK) == 0)
		{
			return(command_path_with_slash);
		}
		free(command_path_with_slash);
		i++;
	}
	ft_free(potential_path);
	return (NULL);
}

int main (int argc, char **argv, char **envp)
{
	// int i = 0;
	char *path;
	
	// error_info(argc);
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


// char	*set_command_path(char *command, char **env)
// {
// 	int	i;
// 	char	*cmd_with_path;
// 	char **potential_path;

// 	i = 0;
// 	potential_path = path_to_env(env);
// 	while (potential_path[i])
// 	{
// 		cmd_with_path = ft_strjoin(path_with_slash(env), command);
// 		if (access(cmd_with_path, F_OK) == 0)
// 		{
// 			return (cmd_with_path);
// 		}
// 		free(cmd_with_path);
// 		i++;
// 	}
// 	ft_free(potential_path);
// 	return (NULL);
// }


