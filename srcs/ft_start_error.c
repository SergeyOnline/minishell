/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:39:04 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 22:21:23 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prompt(int argc, char *argv[])
{
	if (argc != 1)
	{
		ft_putstr_fd("\033[36mwhat do you want, ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd("? -> \033[39m", 1);
	}
	else
		ft_putstr_fd("\033[36mwhat do you want? -> \033[39m", 1);
}

void	ft_start_error(int argc, char *argv[])
{
	if (argc > 2)
	{
		ft_putstr_fd("minishell ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		exit(1);
	}
}
