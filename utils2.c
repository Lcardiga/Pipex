/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcardiga <lcardiga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:35:22 by lcardiga          #+#    #+#             */
/*   Updated: 2022/03/05 18:35:25 by lcardiga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_command(char *s, char **command)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(command[0], 2);
	ft_putstr_fd("\n", 2);
	free_paths(command);
	exit(EXIT_FAILURE);
}

int	check_in_dir(char *command)
{
	if (access(command, F_OK) == 0)
		return (1);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**command;
	char	*path;

	command = ft_split(argv, ' ');
	if (command == NULL)
		error("Split error");
	path = find_path(command, envp);
	if (execve(path, command, envp) == -1)
	{
		free(path);
		free_paths(command);
		error("Execve error");
	}
}
