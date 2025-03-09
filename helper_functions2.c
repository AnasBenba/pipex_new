/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:45:16 by abenba            #+#    #+#             */
/*   Updated: 2025/03/05 14:45:18 by abenba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp, char *av)
{
	char	*path;
	int		i;
	char	**cmd;

	path = NULL;
	i = 0;
	cmd = ft_split(av);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	if (path == NULL)
	{
		error_message_1(cmd[0], ": command not found\n");
		ft_free(cmd);
		exit(1);
	}
	ft_free(cmd);
	return (path);
}

void	path_input(char **cmd, char **cmd_path, char **envp, char *path)
{
	if (access(cmd[0], X_OK) == 0)
	{
		execve(cmd[0], cmd, envp);
		error_message_1("execve", " Error\n");
		free_all(cmd_path, cmd, path);
		exit(1);
	}
	else if (access(cmd[0], F_OK) == 0)
	{
		error_message_1(cmd[0], ": Permission denied\n");
		free_all(cmd_path, cmd, path);
		exit(1);
	}
	else if (ft_strchr(cmd[0], '/') != NULL)
	{
		error_message_1(cmd[0], ": No such file or directory\n");
		free_all(cmd_path, cmd, path);
		exit(1);
	}
}

void	exec_cmd(char **cmd_path, char **envp, char *path, char **cmd)
{
	char	*tmp;
	char	*full_path;
	int		i;

	i = 0;
	tmp = NULL;
	full_path = NULL;
	while (cmd_path[i])
	{
		tmp = ft_strjoin(cmd_path[i], "/");
		full_path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(full_path, X_OK) == 0)
		{
			execve(full_path, cmd, envp);
			free(full_path);
			error_message_1("execve", " Error\n");
			free_all(cmd_path, cmd, path);
			exit(1);
		}
		free(full_path);
		i++;
	}
	if (!cmd_path[i])
		cmd_not_found(cmd_path, cmd, path);
}

void	execut_commend(char **av, char **envp)
{
	char	**cmd_path;
	char	*path;
	char	**cmd;

	path = get_path(envp, av[2]);
	cmd_path = ft_split(path);
	if (!cmd_path)
	{
		free(path);
		exit(1);
	}
	cmd = ft_split(av[2]);
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		cmd_error(cmd, cmd_path, path);
	for_norm(cmd, cmd_path, path);
	path_input(cmd, cmd_path, envp, path);
	check_cmd(cmd, cmd_path, path);
	exec_cmd(cmd_path, envp, path, cmd);
	free_all(cmd_path, cmd, path);
}

void	execut_commend2(char **av, char **envp)
{
	char	*path;
	char	**cmd_path;
	char	**cmd;

	path = get_path(envp, av[3]);
	cmd_path = ft_split(path);
	if (!cmd_path)
	{
		free(path);
		exit(1);
	}
	cmd = ft_split(av[3]);
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		cmd_error(cmd, cmd_path, path);
	for_norm(cmd, cmd_path, path);
	path_input(cmd, cmd_path, envp, path);
	check_cmd(cmd, cmd_path, path);
	exec_cmd(cmd_path, envp, path, cmd);
	free_all(cmd_path, cmd, path);
}
