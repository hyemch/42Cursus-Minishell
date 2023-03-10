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
	if (argv[1] && ft_strncmp(argv[1], "-n", 2) == 0 \
	&& (ft_strncmp(argv[1], "-n-", 3) != 0))
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

	//1. export만 들어온경우 -> 모든 환경변수 출력
	//2. export 변수이름=값
int	ft_export(int argc, char **argv)
{
	t_env	*env;
	int		i;
	char	*env_name;
	char	*env_value;

	i = 1;
	if (argc == 1)
	{
		env_name = env->name;
		env_value = env->value;
		while (env->next != NULL)
		{
			printf("declare -x %s=\"%s\"\n", env_name, env_value);
			env_name = env->name->next;
			env_value = env->value->next;
		}
	}
	while (argv[i] != NULL)
	{
		argv[i] == env_name;
		argv[i + 1]
	}
}

//int	ft_env(char **argv)
//{
//}

void	ft_exit(int argc, char **argv)
{
	int	tmp;

	if (argc == 1)
	{
		printf("exit\n");
		exit(0);
	}
	else if (argc > 2)
		printf("exit: too many arguments\n");
	else
	{
		tmp = ft_atoi(argv[1]);
		printf("exit\n");
		exit(tmp);
	}
}

int	ft_pwd(void)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (tmp == NULL)
	{
		perror("getcwd error");
		free(tmp);
		return (1);
	}
	printf("%s\n", tmp);
	free(tmp);
	return (0);
}

void	leaks(void)
{
	system("leaks ft_echo");
}

int	main(int argc, char **argv)
{
	if (argc < 1)
		return (1);
	atexit(leaks);
}
