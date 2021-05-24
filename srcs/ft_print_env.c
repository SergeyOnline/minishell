/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:07:31 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 22:20:52 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_quots(char *tmp)
{
	char	*addr;

	addr = ft_strchr(tmp, '=');
	ft_putstr_fd("declare -x ", 1);
	while (*tmp)
	{
		if (tmp == addr)
		{
			ft_putstr_fd("=\"", 2);
			tmp++;
			continue;
		}
		ft_putchar_fd(*tmp, 1);
		tmp++;
	}
	if (addr)
		ft_putstr_fd("\"\n", 1);
	else
		ft_putchar_fd('\n', 1);
}

static void	ft_print_env(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strchr(tmp->str, '=') == NULL)
		{
			tmp = tmp->next;
			continue;
		}
		ft_putstr_fd(tmp->str, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}

static void	ft_print_export(t_list *env)
{
	t_list	*env_copy;
	t_list	*tmp;

	env_copy = ft_copy_list(env);
	ft_sort_list(env_copy);
	tmp = env_copy;
	while (tmp)
	{
		ft_print_quots(tmp->str);
		tmp = tmp->next;
	}
	ft_lstclear(&env_copy);
}

void		ft_print(t_list *env, t_list *args, char flag)
{
	if (args->next && flag != 'd')
	{
		ft_putstr_fd("minishell: env: ", 1);
		ft_putstr_fd((args->next)->str, 1);
		ft_putstr_fd(" No such file or directory\n", 1);
	}
	else if (flag == 'd')
		ft_print_export(env);
	else
		ft_print_env(env);
}
