/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:46:10 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/13 16:46:12 by sbroderi         ###   ########.fr       */
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

int				ft_handle_redir(char *line, t_base *base)
{
	char	*str;
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	str = ft_strdup("");
	i += (line[0] == '>') ? 1 : 0;
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
	(tmp) ? fill_tmp(&tmp, str) : 0;
	fd = (line[0] == '>') ? open(tmp, O_RDWR | O_CREAT | O_APPEND, 0644) :
	open(tmp, O_RDWR | O_CREAT | O_TRUNC, 0644);
	free(tmp);
	free(str);
	dup2(fd, 1);
	return (i);
}
