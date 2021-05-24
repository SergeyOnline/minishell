/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:59:45 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 22:19:43 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		check_start_char(int *j, char **line,
	t_base *base, char **content)
{
	*j = 0;
	base->redirflag = 0;
	*content = ft_strdup("");
	ft_skip_spases(line, j);
	if ((*line)[(*j)] == ';' || (*line)[(*j)] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 1);
		if (((*line)[(*j)] == ';' && (*line)[(*j) + 1] == ';') ||
			((*line)[(*j)] == '|' && (*line)[(*j) + 1] == '|'))
			ft_putchar_fd((*line)[(*j)], 1);
		ft_putchar_fd((*line)[(*j)], 1);
		ft_putstr_fd("'\n", 1);
		free(*content);
		return (1);
	}
	return (0);
}

int				check_end_redirect(t_base *base, char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
	{
		ft_lstclear(&base->arg);
		ft_putstr_fd("minishell: ", base->std_out);
		ft_putstr_fd("syntax error near unexpected token `newline'\n",
			base->std_out);
		return (1);
	}
	return (0);
}

static int		check_spaces(char **line, int *j, char **content, t_base *base)
{
	if ((*line)[(*j)] == ' ')
	{
		ft_skip_spases(line, j);
		if (*content)
		{
			if (base->word == 0)
			{
				ft_lstadd_back(&base->arg, new_list(*content));
				*content = ft_strdup("");
			}
			base->word = 0;
		}
		return (1);
	}
	return (0);
}

static void		find_word_and_quots(char **line, int *j,
	t_base *base, char **content)
{
	char *tmp;
	char *tmp_str;

	tmp_str = &(*line)[(*j)];
	if ((tmp = ft_find_word(tmp_str, j, base)) != NULL)
		ft_fill_content_tmp(content, &tmp);
	tmp_str = &(*line)[(*j)];
	if ((tmp = ft_find_quote(tmp_str, j, base)) != NULL)
		ft_fill_content_tmp(content, &tmp);
	tmp_str = &(*line)[(*j)];
	if ((tmp = ft_find_double_quote(tmp_str, j, base)) != NULL)
		ft_fill_content_tmp(content, &tmp);
	if (*content && ((*line)[(*j)] == '\0' || (*line)[(*j)] == ';' ||
		(*line)[(*j)] == '|'))
	{
		if (base->word == 0)
		{
			ft_lstadd_back(&base->arg, new_list(*content));
			*content = ft_strdup("");
		}
		base->word = 0;
	}
}

void			ft_data_parser(t_base *base, char *line)
{
	char	*content;
	int		j;
	char	*str_file;
	int		tmp_int;

	str_file = NULL;
	if (check_start_char(&j, &line, base, &content))
		return ;
	while (line[j])
	{
		if (check_spaces(&line, &j, &content, base))
			continue;
		if ((tmp_int = selector(&line, &j, base, &content)) == 2)
			break ;
		else if (tmp_int == 1)
			continue;
		else if (tmp_int == 3)
			return ;
		find_word_and_quots(&line, &j, base, &content);
	}
	free(content);
}
