/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_selector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:46:46 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/10 08:46:49 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_command_selector(t_base *base, int *hidden_code)
{
	if (base->arg == NULL)
		return ;
	if (base->arg && ft_strncmp(base->arg->str, "env", 4) == 0
		&& (base->arg)->next == NULL)
		ft_print(base->env, base->arg, 'x');
	else if (base->arg && ft_strncmp(base->arg->str, "pwd", 4) == 0)
		ft_pwd();
	else if (base->arg && ft_strncmp(base->arg->str, "cd", 3) == 0)
		ft_cd(base->arg->next, base);
	else if (base->arg && ft_strncmp(base->arg->str, "export", 7) == 0)
		ft_export(base);
	else if (base->arg && ft_strncmp(base->arg->str, "unset", 6) == 0)
		ft_unset(base);
	else if (base->arg && ft_strncmp(base->arg->str, "echo", 5) == 0)
		ft_echo(base);
	else if ((base->arg && ft_strncmp(base->arg->str, "pizza", 6) == 0))
	{
		ft_hidden(*hidden_code);
		*hidden_code += 1;
	}
	else if ((base->arg && ft_strncmp(base->arg->str, "exit", 5) == 0))
		ft_exit(base);
	else if (base->arg)
		ft_exe(base, (base->arg)->str);
}
