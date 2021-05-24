/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidden.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 02:54:25 by Sbroderi          #+#    #+#             */
/*   Updated: 2020/11/10 02:54:29 by Sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_hidden(int code)
{
	if (code == 0)
		ft_putstr_fd("\033[32mNo.\n\033[39m", 1);
	else if (code == 1)
		ft_putstr_fd("\033[32mNO!\n\033[39m", 1);
	else if (code == 2)
		ft_putstr_fd("\033[33mNO! NO! NO!\n\033[39m", 1);
	else if (code == 3)
		ft_putstr_fd("\033[33mAre you serious?\n\033[39m", 1);
	else if (code == 4)
		ft_putstr_fd("\033[33mDo not ask me. I CAN'T DO IT!!!!\n\033[39m", 1);
	else if (code == 5)
		ft_putstr_fd("\033[33mYou're healthy?\n\033[39m", 1);
	else if (code == 6)
		ft_putstr_fd("\033[31mI start to get mad at you!\n\033[39m", 1);
	else if (code == 7)
		ft_putstr_fd("\033[31mOne more request and I will leave!\n\033[39m", 1);
	else if (code == 8)
		ft_putstr_fd("\033[31mYou ... YOU ... AAAGRRHH!!! ...\n\033[39m", 1);
	else if (code == 9)
	{
		ft_putstr_fd("\033[31mNow I am offended by you. \033[39m", 1);
		ft_putstr_fd("\033[31mDo not write to me!! Goodbye!!!\n\033[39m", 1);
		exit(1);
	}
}
