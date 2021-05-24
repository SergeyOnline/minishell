/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:32:37 by ftorn             #+#    #+#             */
/*   Updated: 2020/11/18 12:32:39 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	daughter_process(t_base *base)
{
	if (base->redirflag)
	{
		ft_command_selector(base, 0);
		dup2(base->std_in, 0);
		dup2(base->std_out, 1);
	}
	dup2(base->pipefd[1], 1);
	close(base->pipefd[0]);
	if (base->redirflag == 0)
	{
		ft_command_selector(base, 0);
		dup2(base->std_out, 1);
		dup2(base->std_in, 0);
	}
	close(1);
}

void		ft_handle_pipe(t_base *base)
{
	int		rv;
	int		status;
	pid_t	current_pid;

	rv = 0;
	pipe(base->pipefd);
	current_pid = fork();
	if (current_pid == 0)
	{
		daughter_process(base);
		exit(rv);
	}
	else
	{
		close(base->pipefd[1]);
		dup2(base->pipefd[0], 0);
		waitpid(current_pid, &status, WUNTRACED);
		close(base->pipefd[0]);
		ft_lstclear(&base->arg);
		dup2(base->std_out, 1);
		base->redirflag = 0;
	}
}
