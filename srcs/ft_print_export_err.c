/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_export_err.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:49:46 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 22:21:05 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_export_err(char *str, t_base *base)
{
	ft_putstr_fd("minishell: ", 1);
	ft_putstr_fd("export: \'", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\': not a valid identifier\n", 1);
	base->zigzag = 1;
}
