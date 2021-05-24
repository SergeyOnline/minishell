/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shield.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:24:03 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/19 23:24:05 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_shield(char **content, char *src)
{
	char *tmp;

	if (src[1] && (src[1] == '$' || src[1] == '\\' || src[1] == WQUOTE
		|| src[1] == QUOTE || src[1] == ';' || src[1] == '|'))
	{
		tmp = *content;
		*content = ft_strjoin_char(*content, src[1]);
		free(tmp);
		return (2);
	}
	return (0);
}
