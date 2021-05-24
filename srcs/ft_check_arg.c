/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:45:53 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 22:19:07 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_check_arg(char *arg, t_base *base)
{
	int		i;

	i = -1;
	while (arg[++i] && arg[i] != '=')
	{
		if (arg[i] == '(' || arg[i] == ')')
		{
			ft_putstr_fd("minishell: syntax error near unexpected token '", 1);
			ft_putchar_fd(arg[i], 1);
			ft_putstr_fd("'\n", 1);
			base->zigzag = 258;
			return (2);
		}
		if (!(ft_isalpha(arg[i]) || ft_isdigit(arg[i])) && arg[i] != '_')
		{
			ft_print_export_err(&arg[0], base);
			return (1);
		}
	}
	if (arg[0] == '=' || ft_isdigit(arg[0]))
	{
		ft_print_export_err(&arg[0], base);
		return (1);
	}
	return ((arg[0] == '_' && arg[1] == '\0') ? 1 : 0);
}

int			check_bracket(t_base *base)
{
	int		i;
	char	*arg;
	t_list	*tmp;

	tmp = (base->arg)->next;
	while (tmp)
	{
		arg = tmp->str;
		i = -1;
		while (arg[++i] && arg[i] != '=')
		{
			if (arg[i] == '(' || arg[i] == ')')
			{
				ft_putstr_fd("minishell: ", 1);
				ft_putstr_fd("syntax error near unexpected token '", 1);
				ft_putchar_fd(arg[i], 1);
				ft_putstr_fd("'\n", 1);
				base->zigzag = 258;
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

void		fill_new_value_export(char **new_value, char ch)
{
	char *tmp;

	tmp = *new_value;
	*new_value = ft_strjoin_char(*new_value, ch);
	free(tmp);
}

int			print_err_massage_export(t_list **tmp, t_base *base)
{
	if (*(*tmp)->str == '\0')
	{
		ft_putstr_fd("minishell: export: ", base->std_out);
		ft_putstr_fd("`': not a valid identifier\n", base->std_out);
		base->zigzag = 1;
		*tmp = (*tmp)->next;
		return (1);
	}
	return (0);
}
