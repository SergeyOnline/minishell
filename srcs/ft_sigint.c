/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:45:20 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 22:21:11 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint(void)
{
	if (!g_read)
		ft_putstr_fd("\b\b   \nminishell", 1);
	else
		ft_putchar_fd('\n', 1);
	return ;
}

void	ft_sigquit(void)
{
	if (g_status == 0)
		ft_putstr_fd("\b\b  \b\b", 1);
	else
		ft_putstr_fd("Quit: 3\n", 1);
	return ;
}
