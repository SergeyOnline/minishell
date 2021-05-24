/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_parser_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 03:02:51 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 03:02:55 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_semicolon(char **line, int *j, t_base *base)
{
	char	*sub_line;
	char	*tmp;

	if ((*line)[(*j)] == ';')
	{
		tmp = &(*line)[(*j)];
		if (ft_check_double_pipe_semicolon(tmp))
		{
			ft_lstclear(&base->arg);
			return (2);
		}
		while ((*line)[(*j) + 1] == ' ')
			*j += 1;
		sub_line = ft_substr(*line, 0, *j);
		ft_handle_semicolon(base);
		tmp = &(*line)[*(j) + 1];
		*line = tmp;
		ft_lstclear(&base->arg);
		free(sub_line);
		*j = 0;
		base->redirflag = 0;
		ft_skip_spases(line, j);
		return (1);
	}
	return (0);
}

int		check_pipe(char **line, int *j, t_base *base)
{
	char *tmp;

	if ((*line)[(*j)] == '|')
	{
		tmp = &(*line)[(*j)];
		if (ft_check_double_pipe_semicolon(tmp))
		{
			ft_lstclear(&base->arg);
			return (2);
		}
		base->pipeflag += 1;
		ft_handle_pipe(base);
		*j += 1;
		ft_skip_spases(line, j);
		return (1);
	}
	return (0);
}

int		check_redirrect(char **line, int *j,
	t_base *base, char **content)
{
	char *tmp;

	if ((*line)[(*j)] == '>')
	{
		tmp = &(*line)[(*j) + 1];
		if (check_end_redirect(base, tmp))
			return (2);
		base->redirflag++;
		tmp = &(*line)[(*j)];
		if (ft_check_redir_arg(tmp))
		{
			ft_lstclear(&base->arg);
			return (3);
		}
		if (*content && **content)
		{
			ft_lstadd_back(&base->arg, new_list(*content));
			*content = ft_strdup("");
		}
		*j += 1;
		*j += ft_handle_redir(&(*line)[(*j)], base);
		ft_skip_spases(line, j);
		return (1);
	}
	return (0);
}

int		check_rev_redirrect(char **line, int *j,
	t_base *base, char **content)
{
	char *tmp;

	if ((*line)[(*j)] == '<')
	{
		tmp = &(*line)[(*j) + 1];
		if (check_end_redirect(base, tmp))
			return (2);
		tmp = &(*line)[(*j)];
		if (ft_check_rev_redir_arg(tmp))
		{
			ft_lstclear(&base->arg);
			return (3);
		}
		if (*content && **content)
		{
			ft_lstadd_back(&base->arg, new_list(*content));
			*content = ft_strdup("");
		}
		*j += 1;
		*j += ft_handle_rev_redir(&(*line)[(*j)], base);
		ft_skip_spases(line, j);
		return (1);
	}
	return (0);
}
