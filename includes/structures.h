/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:32:05 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/03 14:32:06 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

typedef struct		s_base
{
	t_list			*env;
	t_list			*arg;
	char			*home;
	int				fd;
	int				pipefd[2];
	int				zigzag;
	int				redirflag;
	int				pipeflag;
	int				std_in;
	int				std_out;
	int				cd_flag;
	int				word;
}					t_base;

typedef struct		s_garbage_tmp
{
	char *tmp;
	char *tmp2;
}					t_garbage_tmp;
#endif
