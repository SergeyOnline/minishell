/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:33:52 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/09 21:10:33 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		handle_ques(char **arg, t_base *base, int *i, char **content)
{
	char	*tmp;
	char	*tmp2;

	tmp = *arg;
	tmp2 = ft_itoa(base->zigzag);
	*arg = ft_strjoin(*arg, tmp2);
	free(tmp);
	free(tmp2);
	*i += 1;
	tmp = *content;
	*content = ft_strjoin(*content, *arg);
	free(tmp);
	free(*arg);
	return (*i);
}

static void		free_tail(char ***array, t_garbage_tmp *g, char **arg)
{
	int	j;

	j = 0;
	while ((*array)[j])
	{
		free((*array)[j]);
		j++;
	}
	free(*array);
	free(g->tmp);
	free(g->tmp2);
	free(*arg);
}

static void		fill_arg(char **src, char **arg, int *i)
{
	char *tmp;

	while ((*src)[(*i)] && (*src)[(*i)] != ' ' &&
		(*src)[(*i)] != WQUOTE && (*src)[(*i)] != '$' && (*src)[(*i)] != '=' &&
		(*src)[(*i)] != ';' && (*src)[(*i)] != QUOTE)
	{
		tmp = *arg;
		*arg = ft_strjoin_char(*arg, (*src)[(*i)]);
		*i += 1;
		free(tmp);
	}
}

int				ft_dollar(char **content, t_base *base, char *src)
{
	int				j;
	int				i;
	t_garbage_tmp	g;
	char			**array;
	char			*arg;

	g.tmp = NULL;
	i = 1;
	if (ft_isdigit(src[2]))
		return (2);
	arg = ft_strdup("");
	if (src[1] == '?')
		return (handle_ques(&arg, base, &i, content));
	fill_arg(&src, &arg, &i);
	g.tmp2 = ft_strdup(find_env_arg(base, arg));
	array = ft_split(g.tmp2, ' ');
	j = -1;
	while (array[++j] && array[j + 1])
		ft_lstadd_back(&base->arg, new_list(ft_strdup(array[j])));
	g.tmp = *content;
	*content = (array[j] != NULL) ? ft_strjoin(*content, array[j]) :
		ft_strdup(*content);
	free_tail(&array, &g, &arg);
	return (i);
}
