/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:06:25 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/05/14 14:06:28 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_check_tail(char **line, char **tail)
{
	char *new_line;
	char *ptr;

	if (*tail)
		if ((new_line = ft_strchr(*tail, '\n')))
		{
			*new_line = '\0';
			if (!(*line = ft_strdup(*tail)))
				return (1);
			ptr = *tail;
			if (!(*tail = ft_strdup(new_line + 1)))
				return (1);
			free(ptr);
		}
		else
		{
			if (!(*line = ft_strdup(*tail)))
				return (1);
			free(*tail);
			*tail = NULL;
		}
	else if (!(*line = ft_strdup("\0")))
		return (1);
	return (0);
}

char		*ft_strdup(const char *s1)
{
	int		count;
	char	*str;

	count = 0;
	while (s1 && s1[count])
		count++;
	str = (char *)malloc(sizeof(*str) * count + 1);
	if (str == NULL)
		return (NULL);
	count = 0;
	while (s1 && s1[count] != '\0')
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		index;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return ((s1 == NULL) ? (char *)s2 : (char *)s1);
	index = 0;
	len = ft_strlen((char *)s1);
	len += ft_strlen((char *)s2);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
		str[index++] = s1[i++];
	i = 0;
	while (s2[i])
		str[index++] = s2[i++];
	str[index] = '\0';
	return (str);
}

char		*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (0);
}
