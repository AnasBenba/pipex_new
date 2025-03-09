/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:02:33 by abenba            #+#    #+#             */
/*   Updated: 2025/03/08 18:02:34 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	for_norm(char **cmd, char **cmd_path, char *path)
{
	if (check(cmd, cmd_path, path) == 1)
	{
		error_message_1(cmd[0], ": command not found\n");
		free_all(cmd_path, cmd, path);
		exit(1);
	}
	else if (check(cmd, cmd_path, path) == 2)
	{
		error_message_1(cmd[0], ": Is a directory\n");
		free_all(cmd_path, cmd, path);
		exit(1);
	}
}

void	check_dot(char **cmd, char **cmd_path, char *path)
{
	if (cmd[0][0] == '.' && cmd[0][1] == '\0')
	{
		error_message_1(".:", " filename argument required\n");
		free_all(cmd_path, cmd, path);
		exit(1);
	}
}
