/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:30:52 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/09 21:09:41 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_find_quote(char *src, int *index, t_base *base)
{
	int		i;
	char	*content;
	char	*tmp;

	if (*src != QUOTE || *src == '\0')
		return (NULL);
	base->word = 0;
	content = ft_strdup("");
	i = 1;
	while (src[i] && src[i] != QUOTE)
	{
		tmp = content;
		content = ft_strjoin_char(content, src[i]);
		free(tmp);
		i++;
	}
	*index += i + 1;
	if (!(*content))
	{
		free(content);
		return (NULL);
	}
	return (content);
}
