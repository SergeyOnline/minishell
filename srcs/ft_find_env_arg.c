/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:36:49 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/09 21:09:01 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env_arg(t_base *base, char *str)
{
	t_list	*tmp;
	int		str_len;

	str_len = ft_strlen(str);
	tmp = base->env;
	while (tmp)
	{
		if ((ft_strncmp(str, tmp->str, str_len)) == 0
			&& tmp->str[str_len] == '=')
			return (&tmp->str[str_len] + 1);
		tmp = tmp->next;
	}
	return (NULL);
}
