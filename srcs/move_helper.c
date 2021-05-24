/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:39:05 by ftorn             #+#    #+#             */
/*   Updated: 2020/11/18 13:39:07 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_helper(t_list **oldpwd, char **s_oldpwd)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	*s_oldpwd = ft_strjoin("OLDPWD=", tmp);
	free(tmp);
	free((*oldpwd)->str);
	(*oldpwd)->str = *s_oldpwd;
}
