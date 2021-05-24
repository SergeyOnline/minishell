/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_semicolon.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:28:36 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/19 23:28:38 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handle_semicolon(t_base *base)
{
	ft_command_selector(base, 0);
	close(base->
		pipefd[0]);
	close(base->pipefd[1]);
	dup2(base->std_in, 0);
	dup2(base->std_out, 1);
	ft_lstclear(&base->arg);
}
