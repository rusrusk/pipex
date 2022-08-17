/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_and_structs_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:38:10 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/16 23:14:12 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_AND_STRUCTS_BONUS_H
# define MACROS_AND_STRUCTS_BONUS_H

# define INFILE_ERROR "Infile error occured!"
# define OUTFILE_ERROR "Outfile error occured!"
# define INPUT_ERROR "Invalid number of arguments!"
# define COMMAND_ERROR "Error: command not found!"

// enum	e_standard_value
// {
// 	STDIN = 0,
// 	STDOUT = 1,
// 	STDERR = 2,
// };

// enum e_return
// {
// 	ERROR = -1,
// 	SUCCESS = 0,
// };

typedef struct e_source
{
	char	*env_path;
	char	*command_path;
	char	**command;
	char	*line;
	pid_t	pid;
	int		idx;
	int		infile;
	int		outfile;	
	int		pipefd[2];
}	t_source;

#endif