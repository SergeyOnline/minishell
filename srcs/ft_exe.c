/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:09:39 by ftorn             #+#    #+#             */
/*   Updated: 2020/11/20 22:13:12 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

static char		*ft_find_command(t_base *base)
{
	char	*res;
	char	**for_split;
	t_list	*path;
	int		i;

	if ((path = ft_find_path(&base->env, "PATH", EQUAL)) == NULL)
	{
		ft_error_exe(base, NULL, 3);
		return (NULL);
	}
	for_split = ft_split(ft_strchr(path->str, '=') + 1, ':');
	res = ft_get_elem_from_split(for_split, base);
	i = -1;
	while (for_split[++i])
		free(for_split[i]);
	free(for_split);
	return (res);
}

static void		end_fork(char **command, int *fd, t_base *base)
{
	if (*fd == -1 && (*command)[0] == '/')
		ft_error_exe(base, *command, 1);
	else if (*fd == -1)
		ft_error_exe(base, *command, 2);
}

void			ft_forks(char *command, char **argv,
	char **env_execve, t_base *base)
{
	pid_t	pid;
	int		rv;
	int		status;
	int		fd;

	fd = 0;
	if (command && (fd = open(command, O_RDONLY)) != -1)
	{
		pid = fork();
		if (pid == 0)
		{
			rv = execve(command, argv, env_execve);
			exit(rv);
		}
		else if (pid == -1)
			ft_putstr_fd(strerror(errno), 1);
		else
		{
			g_status = 1;
			waitpid(pid, &status, WUNTRACED);
			(status != 0) ? base->zigzag = WEXITSTATUS(status) : 0;
		}
	}
	end_fork(&command, &fd, base);
}

static char		*ft_get_arg(char *str)
{
	char	*command;
	char	*tmp;
	int		i;

	i = 0;
	command = ft_strdup("");
	while (str[i] != '\0' && str[i] != ' ')
	{
		tmp = command;
		command = ft_strjoin_char(command, str[i]);
		free(tmp);
		i++;
	}
	return (command);
}

void			ft_exe(t_base *base, char *str)
{
	char	**argv;
	char	**env_execve;
	char	*command;
	char	*tmp;

	argv = NULL;
	if ((str[0] == '.' && str[1] == '.' && str[2] == '/')
		|| (str[0] == '.' && str[1] == '/') || str[0] == '/')
		command = ft_get_arg(str);
	else
		command = ft_find_command(base);
	tmp = (base->arg)->str;
	(base->arg)->str = command;
	argv = ft_array(base->arg);
	env_execve = ft_array(base->env);
	ft_forks(command, argv, env_execve, base);
	free((base->arg)->str);
	(base->arg)->str = tmp;
	free(argv);
	free(env_execve);
}
