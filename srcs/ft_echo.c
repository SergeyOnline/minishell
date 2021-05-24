/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 05:14:38 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/10 05:14:40 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_check_n(char *arg)
{
	int	i;

	if (arg[0] != '-')
		return (0);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void		print_path_arg(t_base *base, t_list **tmp, char **s)
{
	t_list	*path;

	path = ft_find_path(&base->env, "HOME", EQUAL);
	if (path)
		*s = ft_strchr(path->str, '=') + 1;
	(*s) ? ft_putstr_fd(*s, 1) : ft_putstr_fd(base->home, 1);
	if ((*tmp)->str[1])
		ft_putstr_fd(&(*tmp)->str[1], 1);
	if ((*tmp)->next)
		ft_putchar_fd(' ', 1);
	*tmp = (*tmp)->next;
}

static int		while_main(t_base *base, t_list **tmp, int *flag, char **s)
{
	if (ft_check_n((*tmp)->str))
	{
		*flag = 1;
		*tmp = (*tmp)->next;
		return (1);
	}
	if ((*tmp)->str[0] == '~' && ((*tmp)->str[1] == '\0'
		|| (*tmp)->str[1] == '/'))
	{
		print_path_arg(base, tmp, s);
		return (1);
	}
	return (0);
}

void			ft_echo(t_base *base)
{
	t_list	*tmp;
	int		flag;
	char	*s;

	s = NULL;
	flag = 0;
	if (!((base->arg)->next))
		ft_putchar_fd('\n', 1);
	else
	{
		tmp = (base->arg)->next;
		while (tmp)
		{
			if ((while_main(base, &tmp, &flag, &s)) == 1)
				continue;
			((tmp->str)[0] == '\\' && (tmp->str)[1] == '$') ?
				ft_putstr_fd(&(tmp->str)[1], 1) : ft_putstr_fd(tmp->str, 1);
			(tmp->next) ? ft_putchar_fd(' ', 1) : 0;
			tmp = tmp->next;
		}
	}
	(!flag && (base->arg)->next) ? ft_putchar_fd('\n', 1) : 0;
	base->zigzag = 0;
}
