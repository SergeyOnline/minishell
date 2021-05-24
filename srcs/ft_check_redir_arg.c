/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redir_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:31:24 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 22:19:23 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_redir_arg(char *line)
{
	int	i;

	i = 1;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '>')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == ';' || line[i] == '|' || line[i] == '<')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 1);
		ft_putchar_fd(line[i], 1);
		ft_putstr_fd("'\n", 1);
		return (1);
	}
	return (0);
}

int	ft_check_rev_redir_arg(char *line)
{
	int	i;

	i = 1;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == ';' || line[i] == '|' || line[i] == '<')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 1);
		ft_putchar_fd(line[i], 1);
		ft_putstr_fd("'\n", 1);
		return (1);
	}
	return (0);
}
