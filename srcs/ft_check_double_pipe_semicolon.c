/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double_pipe_semicolon.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:33:58 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 22:19:16 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_double_pipe_semicolon(char *line)
{
	int	i;

	i = 1;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == ';' || line[i] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 1);
		if (line[0] == ';' && line[1] == ';')
			ft_putchar_fd(line[0], 1);
		ft_putchar_fd(line[0], 1);
		ft_putstr_fd("'\n", 1);
		return (1);
	}
	return (0);
}
