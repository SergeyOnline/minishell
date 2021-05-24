/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:29:11 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/09 21:53:27 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*new_list(char *str)
{
	t_list *list;

	if ((list = (t_list *)malloc(sizeof(*list))))
	{
		list->str = str;
		list->next = NULL;
	}
	else
		return (NULL);
	return (list);
}

void		ft_lstclear(t_list **lst)
{
	t_list *ptr;
	t_list *next_l;

	if (!lst)
		return ;
	while (*lst)
	{
		ptr = *lst;
		next_l = (ptr->next);
		free(ptr->str);
		free(ptr);
		*lst = next_l;
	}
}

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *ptr;

	ptr = *lst;
	if (new)
	{
		if (ptr)
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = new;
		}
		else
			*lst = new;
	}
	else
		ft_lstclear(lst);
}

t_list		*ft_copy_list(t_list *list)
{
	t_list *new;

	new = NULL;
	while (list != NULL)
	{
		ft_lstadd_back(&new, new_list(ft_strdup(list->str)));
		list = list->next;
	}
	return (new);
}

void		ft_sort_list(t_list *list)
{
	int		flag;
	t_list	*tmp;

	flag = 1;
	while (flag)
	{
		flag = 0;
		tmp = list;
		while ((tmp->next) != NULL)
		{
			if (ft_strcmp(tmp->str, (tmp->next)->str) == 1)
			{
				ft_swap_str(&tmp->str, &(tmp->next)->str);
				flag = 1;
			}
			tmp = tmp->next;
		}
	}
}
