/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 00:22:44 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/20 00:22:46 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_skip_spases(char **line, int *j)
{
	while ((*line)[(*j)] && (*line)[(*j)] == ' ')
		*j += 1;
}
