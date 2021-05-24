/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:33:27 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 22:20:12 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_is_digits_in_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

static void		ft_print_numeric_error(char *str, int fd, t_base *base)
{
	(base->pipeflag == 0) ? ft_putstr_fd("exit\n", fd) : 0;
	ft_putstr_fd("minishell: exit: ", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(": numeric argument required\n", fd);
	base->zigzag = 1;
}

static void		if_not_digit(t_base *base, t_list *tmp)
{
	if (!(ft_is_digits_in_str(tmp->str)))
	{
		ft_print_numeric_error(tmp->str, base->std_out, base);
		if (base->pipeflag)
			return ;
		exit(255);
	}
	(base->pipeflag == 0) ? ft_putstr_fd("exit\n", base->std_out) : 0;
	ft_putstr_fd("minishell: exit: ", base->std_out);
	ft_putstr_fd("too many arguments\n", base->std_out);
	base->zigzag = 1;
}

static	int		check_digit_in_str(t_base *base, t_list **tmp)
{
	if (!(ft_is_digits_in_str((*tmp)->str)))
	{
		ft_print_numeric_error((*tmp)->str, base->std_out, base);
		if (base->pipeflag)
			return (1);
		exit(255);
	}
	return (0);
}

void			ft_exit(t_base *base)
{
	t_list *tmp;

	close(base->fd);
	tmp = (base->arg)->next;
	if (tmp)
	{
		if (tmp->next)
		{
			if_not_digit(base, tmp);
			return ;
		}
		if (check_digit_in_str(base, &tmp))
			return ;
		(base->pipeflag == 0) ? ft_putstr_fd("exit\n", base->std_out) : 0;
		if (base->pipeflag)
			return ;
		exit(ft_atoi(tmp->str));
	}
	else
	{
		if (base->pipeflag)
			return ;
		exit(base->zigzag);
	}
}
