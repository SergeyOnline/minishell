/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_rev_redir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:54:38 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/17 18:54:39 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		trim_str(char **str, char *arg)
{
	char *tmp;

	tmp = *str;
	*str = ft_strtrim(*str, arg);
	free(tmp);
}

static	void	fill_tmp(char **tmp, char *str)
{
	char *tmp_str;

	tmp_str = *tmp;
	*tmp = ft_strdup(*tmp);
	free(tmp_str);
	tmp_str = *tmp;
	*tmp = ft_strjoin_char(*tmp, '/');
	free(tmp_str);
	tmp_str = *tmp;
	*tmp = ft_strjoin(*tmp, str);
	free(tmp_str);
}

static int		find_word_and_quots(char **line, char **str, t_base *base)
{
	char	*tmp;
	char	*tmp_line;
	int		j;

	j = 0;
	tmp_line = *line;
	if ((tmp = ft_find_word(&tmp_line[j], &j, base)) != NULL)
		ft_fill_content_tmp(str, &tmp);
	if ((tmp = ft_find_quote(&tmp_line[j], &j, base)) != NULL)
		ft_fill_content_tmp(str, &tmp);
	if ((tmp = ft_find_double_quote(&tmp_line[j], &j, base)) != NULL)
		ft_fill_content_tmp(str, &tmp);
	return (j);
}

int				ft_handle_rev_redir(char *line, t_base *base)
{
	char	*str;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	str = ft_strdup("");
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i] != '\0' && line[i] != '>' &&
		line[i] != ';' && line[i] != '<')
	{
		tmp = &line[i];
		i += find_word_and_quots(&tmp, &str, base);
	}
	trim_str(&str, " ");
	tmp = getcwd(NULL, 0);
	if (tmp)
		fill_tmp(&tmp, str);
	fd = open(tmp, O_RDONLY);
	free(tmp);
	free(str);
	dup2(fd, 0);
	return (i);
}
