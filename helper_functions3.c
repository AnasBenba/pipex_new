/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:49:01 by abenba            #+#    #+#             */
/*   Updated: 2025/03/05 14:49:03 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_not_found(char **cmd_path, char **cmd, char *path)
{
	error_message_1(cmd[0], ": command not found\n");
	ft_free(cmd_path);
	ft_free(cmd);
	free(path);
	exit(1);
}

void	free_all(char **cmd_path, char **cmd, char *path)
{
	ft_free(cmd_path);
	ft_free(cmd);
	if (path)
		free(path);
}

void	is_qou(char **ptr, char const *s, int i, size_t *y)
{
	(*ptr)[*y] = s[i];
	(*y)++;
}

void	check_cmd(char **cmd, char **cmd_path, char *path)
{
	if (cmd[0][0] == '/')
	{
		error_message_1("command", " not found\n");
		free_all(cmd_path, cmd, path);
		exit(1);
	}
}

int	check(char **cmd, char **cmd_path, char *path)
{
	int (i) = 0;
	int (count) = 0;
	int (count_sla) = 0;
	check_dot(cmd, cmd_path, path);
	while (cmd[0][i])
	{
		if (cmd[0][i] == '/')
			count_sla++;
		else if (cmd[0][i] == '.')
			count++;
		else
			return (3);
		i++;
	}
	if (count == 0 && count_sla != 0)
		return (2);
	else if (count != 0 && count_sla == 0)
		return (1);
	else if (count <= 2 && count_sla <= 1)
		return (2);
	else if (count != 0 && count_sla >= 1)
		return (2);
	else
		return (3);
	return (1);
}
