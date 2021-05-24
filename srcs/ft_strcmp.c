/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:11:55 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/05/01 12:11:58 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t i;

	i = 0;
	while ((str1[i] != '\0') && (str1[i] == str2[i]))
		i++;
	if ((unsigned int)str1[i] > (unsigned int)str2[i])
		return (1);
	else if ((unsigned int)str1[i] < (unsigned int)str2[i])
		return (-1);
	return (0);
}
