/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:42:19 by abenba            #+#    #+#             */
/*   Updated: 2025/03/05 14:42:21 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_0_error(int pip[], char **av)
{
	if (access(av[1], F_OK) == 0)
	{
		error_message_1(av[1], ": permission denied\n");
		exit(1);
	}
	else
	{
		error_message_1(av[1], ": No such file or directory\n");
		exit(1);
	}
	close(pip[0]);
	close(pip[1]);
}

void	fd_1_error(int fd[], int pip[])
{
	close(fd[0]);
	close(pip[0]);
	close(pip[1]);
}

void	fork_error(int pip[])
{
	close_fds(pip);
	error_message_1("Fork", " Error\n");
	exit(1);
}

void	cmd_error(char **cmd, char **cmd_path, char *PATH)
{
	error_message_1(cmd[0], ": command not found\n");
	ft_free(cmd_path);
	ft_free(cmd);
	free(PATH);
	exit(1);
}
