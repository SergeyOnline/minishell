/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:10:02 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/08 17:10:05 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_change_value(t_list **list, char *str)
{
	char	*tmp;
	char	*value;
	char	*new_value;
	int		i;

	i = -1;
	tmp = ft_strchr(str, '=');
	if (!tmp)
		return ;
	value = ft_strdup(tmp + 1);
	new_value = ft_strdup("");
	while (str[++i] != '=')
		fill_new_value_export(&new_value, str[i]);
	fill_new_value_export(&new_value, EQUAL);
	tmp = new_value;
	new_value = ft_strjoin(new_value, value);
	free(tmp);
	free(value);
	tmp = (*list)->str;
	(*list)->str = new_value;
	free(tmp);
}

static void		check_and_fill_args(char **s, t_list *tmp, char *flag)
{
	char	*t;
	int		i;

	if (ft_strchr(tmp->str, EQUAL))
	{
		i = -1;
		while (tmp->str[++i] != EQUAL)
		{
			t = *s;
			*s = ft_strjoin_char(*s, tmp->str[i]);
			free(t);
		}
		*flag = EQUAL;
	}
	else
	{
		t = *s;
		*s = ft_strjoin(*s, tmp->str);
		free(t);
		*flag = TERM;
	}
}

static	int		check_args(t_list **tmp, t_base *base, char **s)
{
	if (ft_check_arg((*tmp)->str, base))
	{
		free(*s);
		*tmp = (*tmp)->next;
		return (1);
	}
	return (0);
}

static void		else_main(t_base *base, char *flag)
{
	t_list	*tmp;
	t_list	*ptr;
	char	*s;

	tmp = (base->arg)->next;
	while (tmp)
	{
		if (print_err_massage_export(&tmp, base))
			continue;
		s = ft_strdup("");
		if (check_args(&tmp, base, &s))
			continue;
		check_and_fill_args(&s, tmp, flag);
		if ((ptr = ft_find_path(&base->env, s, *flag)))
			ft_change_value(&ptr, tmp->str);
		else if ((!(ft_find_path(&base->env, s, TERM)))
			&& (!(ft_find_path(&base->env, s, EQUAL))))
			ft_lstadd_back(&base->env, new_list(ft_strdup(tmp->str)));
		else if ((ptr = ft_find_path(&base->env, s, TERM)))
			ft_change_value(&ptr, tmp->str);
		tmp = tmp->next;
		free(s);
	}
}

void			ft_export(t_base *base)
{
	char	flag;

	flag = 'E';
	base->zigzag = 0;
	if (check_bracket(base))
		return ;
	if ((base->arg)->next == NULL)
		ft_print(base->env, base->arg, 'd');
	else
		else_main(base, &flag);
}
