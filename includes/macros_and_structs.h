/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_and_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkultaev <rkultaev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:01:25 by rkultaev          #+#    #+#             */
/*   Updated: 2022/08/14 18:46:40 by rkultaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_AND_STRUCTS_H
# define MACROS_AND_STRUCTS_H

# define INFILE_ERROR "Infile error occured!"
# define OUTFILE_ERROR "Outfile error occured!"
# define INPUT_ERROR "Invalid number of arguments!"
# define COMMAND_ERROR "Error: command not found!"

enum	e_standard_value
{
	STDIN = 0,
	STDOUT = 1,
	STDERR = 2,
};

enum e_return
{
	ERROR = -1,
	SUCCESS = 0,
};

typedef struct e_data
{
	pid_t	child1;
	pid_t	child2;
	int		infile;
	int		outfile;
	int		pipefd[2];
	char	**command;
	char	*proper_path_to_cmd;
}	t_data;

#endif