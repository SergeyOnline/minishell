/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:46:10 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/05/04 13:46:12 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_c_sub(char const *str, char c)
{
	int	i;
	int	count;
	int	substr;

	i = 0;
	count = 0;
	substr = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			i++;
			if (!substr)
				substr = 1;
		}
		if (substr)
		{
			count++;
			substr = 0;
		}
	}
	return (count);
}

static int	ft_len_substr(char const *str, int *start, char delimiter)
{
	int len;

	len = 0;
	while (str[*start] && str[*start] != delimiter)
	{
		*start += 1;
		len++;
	}
	return (len);
}

static char	**ft_clr_mem(char **arr)
{
	int j;

	j = -1;
	while (arr[++j])
		free(arr[j]);
	free(arr);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		i_new_substr;
	int		substr_len;
	char	**result;
	char	**array;

	i = 0;
	if (!s || !(result = (char **)ft_calloc(ft_c_sub(s, c) + 1, sizeof(s))))
		return (NULL);
	array = result;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		i_new_substr = i;
		substr_len = ft_len_substr(s, &i, c);
		if (!(*result = ft_calloc(substr_len + 1, sizeof(char))))
			return (ft_clr_mem(array));
		*result = ft_memcpy(*result, &s[i_new_substr], substr_len);
		result++;
	}
	return (array);
}
