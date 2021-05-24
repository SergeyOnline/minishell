/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:30:00 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 22:19:29 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_copy_env(t_base *base, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if ((ft_strncmp(env[i], "HOME=", 5)) == 0)
			base->home = ft_strdup((ft_strchr(env[i], EQUAL) + 1));
		ft_lstadd_back(&base->env, new_list(ft_strdup(env[i])));
	}
	if (!(base->env))
	{
		ft_putstr_fd("minishell: not created copy ENV ", 1);
		exit(0);
	}
}
