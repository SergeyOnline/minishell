/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorn <ftorn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:30:49 by ftorn             #+#    #+#             */
/*   Updated: 2020/05/14 14:51:10 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_check(const char *s1, const char *set)
{
	while (*set != '\0')
	{
		if (*set == *s1)
			return (1);
		else
			set++;
	}
	return (0);
}

static size_t	ft_smartlen(const char *start, const char *finish)
{
	size_t	len;

	len = 0;
	while (start != finish)
	{
		start++;
		len++;
	}
	return (len + 2);
}

static char		*ft_copy(const char *start, const char *finish)
{
	char	*res;
	char	*res2;

	res = (char*)malloc(ft_smartlen(start, finish) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res2 = res;
	while (start != finish)
	{
		*res = *start;
		res++;
		start++;
	}
	*res = *start;
	if (*start != '\0')
		*(res + 1) = '\0';
	return (res2);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*finish;

	if (s1 == NULL)
		return (NULL);
	while ((ft_check(s1, set) == 1) && *s1 != '\0')
		s1++;
	start = s1;
	while (*s1 != '\0')
	{
		if (ft_check(s1, set) == 1)
		{
			finish = s1 - 1;
			while ((ft_check(s1, set) == 1) && *s1 != '\0')
				s1++;
		}
		else
		{
			s1++;
			finish = s1;
		}
	}
	if (*start == '\0')
		finish = start;
	return (ft_copy(start, finish));
}
