/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:47:53 by rkultaev          #+#    #+#             */
/*   Updated: 2022/07/17 17:47:05 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft42_pipex/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

int		find_path_var(char **str);
char	**path_to_env( char **envp);
void	error_info(int argc);
char	*path_with_slash(char **env);
void	error_handle(char *message);
void	ft_free(char **str);
char	*set_command_path(char *command, char **env);
void	first_process(int *fd, int *pipefd, char **argv, char **env);
void	second_process(int *fd, int *pipefd, char **argv, char **env);
void	pipex(int *fd, int *pipefd, char **argv, char **envp);

void	check_commands(int argc, char **argv, char **env);
void	here_doc(char *argv[]);

#endif