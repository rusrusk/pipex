/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:36:31 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/16 23:31:38 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <time.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft42_pipex/libft.h"
# include "macros_and_structs_bonus.h"
# include "pipex.h"

int		prompt_system_error(void);
void	prompt_error_message(void);
// char	*set_command_path(char *command, char **env);
void	execute(t_source *source, char *argv, char **env);
void	child (t_source *source, char *argv, char **env);
void	here_doc(t_source *source, int argc, char *limiter);
int		open_file(char *argv, int i);

#endif