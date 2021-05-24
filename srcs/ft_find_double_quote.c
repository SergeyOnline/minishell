/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_double_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:32:21 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/09 21:44:07 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		fill_slash(char **content, int *i, char **src)
{
	char *tmp;

	if (!((*src)[(*i) + 1]))
	{
		*i += 1;
		return ;
	}
	if ((*src)[(*i) + 1] != '\"' && (*src)[(*i) + 1] != '$')
	{
		tmp = *content;
		*content = ft_strjoin_char(*content, (*src)[(*i)]);
		free(tmp);
	}
	*i += (ft_shield(content, &(*src)[(*i)]) == 2) ? 2 : 1;
}

static void		fill_content(char **content, char **src, int *i)
{
	char	*tmp;

	tmp = *content;
	*content = ft_strjoin_char(*content, (*src)[(*i)]);
	free(tmp);
	*i += 1;
}

char			*ft_find_double_quote(char *src, int *index, t_base *base)
{
	int		i;
	char	*content;

	if (*src != WQUOTE || *src == '\0')
		return (NULL);
	base->word = 0;
	content = ft_strdup("");
	i = 1;
	while (src[i] && src[i] != WQUOTE)
	{
		if (src[i] == '\\' && src[i + 1] != '\'')
		{
			fill_slash(&content, &i, &src);
			continue;
		}
		if (src[i] == '$' && src[i + 1] != '\\')
		{
			i += ft_dollar(&content, base, &src[i]);
			continue;
		}
		fill_content(&content, &src, &i);
	}
	*index += i + 1;
	return (content);
}
