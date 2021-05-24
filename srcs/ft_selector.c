/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 03:06:14 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 03:06:17 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		selector(char **line, int *j, t_base *base, char **content)
{
	int tmp_int;

	if ((tmp_int = check_semicolon(line, j, base)) == 2)
		return (2);
	else if (tmp_int == 1)
		return (1);
	if ((tmp_int = check_pipe(line, j, base)) == 2)
		return (2);
	else if (tmp_int == 1)
		return (1);
	if ((tmp_int = check_redirrect(line, j, base, content)) == 2)
		return (2);
	else if (tmp_int == 1)
		return (1);
	else if (tmp_int == 3)
		return (3);
	if ((tmp_int = check_rev_redirrect(line, j, base, content)) == 2)
		return (2);
	else if (tmp_int == 1)
		return (1);
	else if (tmp_int == 3)
		return (3);
	return (0);
}
