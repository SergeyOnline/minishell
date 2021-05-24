/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_content_tmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:58:39 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/19 17:58:41 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fill_content_tmp(char **content, char **tmp)
{
	char	*t;

	t = *content;
	*content = ft_strjoin(*content, *tmp);
	if (*tmp)
		free(*tmp);
	free(t);
}
