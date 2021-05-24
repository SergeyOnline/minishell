/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:40:16 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/08 16:46:39 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_read;
int		g_status;

static void		fill_start_args(t_base *base, int *hidden_code)
{
	*hidden_code = 0;
	base->env = NULL;
	base->arg = NULL;
	base->std_in = dup(0);
	base->std_out = dup(1);
	base->zigzag = 0;
	base->arg = NULL;
	base->word = 0;
}

static void		update_fd(t_base *base)
{
	close(base->pipefd[0]);
	close(base->pipefd[1]);
	dup2(base->std_in, 0);
	dup2(base->std_out, 1);
}

int				main(int argc, char *argv[], char *env[])
{
	char	*line;
	t_base	base;
	int		hidden_code;

	fill_start_args(&base, &hidden_code);
	ft_start_error(argc, argv);
	ft_copy_env(&base, env);
	signal(SIGINT, (void*)ft_sigint);
	signal(SIGQUIT, (void*)ft_sigquit);
	while (1)
	{
		g_read = 0;
		g_status = 0;
		base.pipeflag = 0;
		line = NULL;
		ft_prompt(argc, argv);
		get_next_line(0, &line);
		ft_data_parser(&base, line);
		ft_command_selector(&base, &hidden_code);
		update_fd(&base);
		free(line);
		ft_lstclear(&base.arg);
	}
	return (0);
}
