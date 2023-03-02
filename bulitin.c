/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulitin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyecheon <hyecheon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:19:36 by hyecheon          #+#    #+#             */
/*   Updated: 2023/03/02 17:19:39 by hyecheon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **argv)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (argv[1] && ft_strncmp(argv[1], "-n", 2) == 0)
	{
		n = 1;
		i++;
	}
	while (argv[i] != NULL)
	{
		printf("%s", argv[i]);
		if (argv[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (n != 1)
		printf("\n");
	return (0);
}

int	ft_cd(char **argv)
{
	char	*path;

	if (argv[1] == NULL || ft_strncmp(argv[1], "~", 1) == 0)
		path = ft_strdup(getenv("HOME"));
	else
		path = ft_strdup(argv[1]);
	if (chdir(path) != 0)
	{
		printf("cd : no such file or directory: %s", path);
		free(path);
		exit(EXIT_FAILURE);
	}
	free(path);
	return (0);
}
