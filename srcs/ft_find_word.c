/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:29:17 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/09 21:52:52 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	fill_cont(char **content, char ch)
{
	char *tmp;

	tmp = *content;
	*content = ft_strjoin_char(*content, ch);
	free(tmp);
}

static void		fill_slash(char **content, char **src, int *i)
{
	if (!((*src)[(*i) + 1]))
	{
		*i += 1;
		return ;
	}
	*i += (ft_shield(content, &((*src)[(*i)])) == 2) ? 2 : 1;
}

static int		handle_dollar(char **src, int *i, t_base *base, char **content)
{
	if ((*src)[(*i)] == '$' && (*src)[(*i) + 1] != '\\')
	{
		if ((*src)[(*i) + 1] == '\0')
		{
			fill_cont(content, (*src)[(*i)]);
			*i += 1;
			return (2);
		}
		if ((*src)[(*i) + 1] == '$')
		{
			*i += 1;
			return (1);
		}
		*i += ft_dollar(content, base, &((*src)[(*i)]));
		return (1);
	}
	return (0);
}

static int		check_while(char **src, int *i)
{
	if ((*src)[(*i)] && (!((*src)[(*i)] == QUOTE || (*src)[(*i)] == WQUOTE
	|| (*src)[(*i)] == ';' || (*src)[(*i)] == ' ' || (*src)[(*i)] == '|'
	|| (*src)[(*i)] == '>' || (*src)[(*i)] == '<')))
		return (1);
	return (0);
}

char			*ft_find_word(char *src, int *index, t_base *base)
{
	int		i;
	char	*content;
	int		flag;

	if (*src == QUOTE || *src == WQUOTE || *src == '\0')
		return (NULL);
	content = ft_strdup("");
	i = 0;
	while (check_while(&src, &i))
	{
		if (src[i] == '\\')
		{
			fill_slash(&content, &src, &i);
			continue;
		}
		flag = (handle_dollar(&src, &i, base, &content));
		if (flag == 1)
			continue;
		else if (flag == 2)
			break ;
		fill_cont(&content, src[i++]);
	}
	*index += i;
	base->word = (*content) ? 0 : 1;
	return (content);
}
