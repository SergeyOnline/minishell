/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:44:19 by ftorn             #+#    #+#             */
/*   Updated: 2020/11/20 22:22:07 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_check_value(char *variable)
{
	int i;

	i = -1;
	while (variable[++i] != '\0')
		if (variable[i] == '-' || variable[i] == '+' ||
			(ft_isalpha(variable[0]) != 1 && variable[0] != '_'))
		{
			ft_putstr_fd("minishell: unset: `", 1);
			ft_putstr_fd(variable, 1);
			ft_putstr_fd("': not a valid identifier\n", 1);
			return (1);
		}
	i = -1;
	while (variable[++i] != '\0')
		if (variable[i] == ')' || variable[i] == '('
			|| variable[i] == '=')
		{
			ft_putstr_fd("minishell: syntax error near unexpected token '", 1);
			ft_putchar_fd(variable[i], 1);
			ft_putstr_fd("'\n", 1);
		}
	return (0);
}

static void		free_to_del(t_list *to_del)
{
	free(to_del->str);
	free(to_del);
}

static int		error_unset(t_base *base, t_list **tmp)
{
	if ((*tmp)->str == '\0')
	{
		ft_putstr_fd("minishell: unset: ", base->std_out);
		ft_putstr_fd("`': not a valid identifier\n", base->std_out);
		base->zigzag = 1;
		*tmp = (*tmp)->next;
		return (1);
	}
	return (0);
}

static void		unset_loop(t_list **to_del, t_list **tmp, t_list **prev)
{
	while (*to_del && (*to_del)->str &&
		ft_strncmp((*to_del)->str, (*tmp)->str, ft_strlen((*tmp)->str)))
	{
		*prev = *to_del;
		*to_del = (*to_del)->next;
	}
}

void			ft_unset(t_base *base)
{
	t_list	*to_del;
	t_list	*prev;
	t_list	*tmp;

	base->zigzag = 0;
	tmp = (base->arg)->next;
	while (tmp)
	{
		if (error_unset(base, &tmp))
			continue;
		if ((ft_check_value(tmp->str)) != 0)
			return ;
		prev = NULL;
		to_del = base->env;
		unset_loop(&to_del, &tmp, &prev);
		if (to_del && prev)
			prev->next = to_del->next;
		else if (to_del == base->env && base->env && (base->env)->next)
			base->env = (base->env)->next;
		if (to_del)
			free_to_del(to_del);
		tmp = tmp->next;
	}
}
