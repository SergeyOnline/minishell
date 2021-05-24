/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:32:59 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/05/03 21:33:05 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	eval_len;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)(ft_strlen((char *)s)))
		eval_len = 0;
	else
	{
		eval_len = (ft_strlen((char *)s) - start + 1);
		if (eval_len >= len)
			eval_len = len;
	}
	if (!(str = (char *)malloc(sizeof(*str) * eval_len + 1)))
		return (NULL);
	while (i < eval_len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
