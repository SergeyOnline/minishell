/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:09:50 by ftorn             #+#    #+#             */
/*   Updated: 2020/11/20 22:20:03 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_error_exe(t_base *base, char *command, int code)
{
	if (code == 1)
	{
		ft_putstr_fd("minishell: ", 1);
		ft_putstr_fd(command, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		base->zigzag = 127;
	}
	else if (code == 2)
	{
		ft_putstr_fd("minishell: ", 1);
		ft_putstr_fd(command, 1);
		ft_putstr_fd(": command not found\n", 1);
		base->zigzag = 127;
	}
	else if (code == 3)
	{
		ft_putstr_fd("minishell: ", 1);
		ft_putstr_fd((base->arg)->str, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
		base->zigzag = 127;
	}
}

char		**ft_array(t_list *arguments)
{
	char	**res;
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = arguments;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if ((res = (char**)malloc(sizeof(char*) * (i + 1))) == NULL)
		return (NULL);
	tmp = arguments;
	res[i] = NULL;
	while (j < i)
	{
		res[j] = tmp->str;
		tmp = tmp->next;
		j++;
	}
	return (res);
}

void		fill_res(char **res, t_base *base)
{
	char *tmp;

	tmp = *res;
	*res = ft_strjoin(*res, (base->arg)->str);
	free(tmp);
}

char		*ft_get_elem_from_split(char **for_split, t_base *base)
{
	char	*tmp;
	char	*res;
	int		i;

	i = -1;
	res = NULL;
	while (for_split[++i])
	{
		tmp = res;
		res = ft_strjoin_char(for_split[i], '/');
		free(tmp);
		if (base->arg)
			fill_res(&res, base);
		if ((base->fd = open(res, O_RDONLY) != -1))
			break ;
	}
	if (for_split[i] == NULL && base->arg && (base->arg)->str)
	{
		free(res);
		res = ft_strdup((base->arg)->str);
	}
	return (res);
}
