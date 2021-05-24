/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:41:31 by ftorn             #+#    #+#             */
/*   Updated: 2020/11/20 22:18:46 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_error_cd(char *path, t_base *base, int code)
{
	if (code == 1)
	{
		ft_putstr_fd("minishell cd: ",
			base->std_out);
		ft_putstr_fd(path, base->std_out);
		ft_putstr_fd(" No such file or directory\n", base->std_out);
		base->zigzag = 1;
	}
	else if (code == 2)
	{
		ft_putstr_fd("minishell :", base->std_out);
		ft_putstr_fd(" cd: OLDPWD not set\n", base->std_out);
		base->zigzag = 1;
	}
	else if (code == 3)
	{
		ft_putstr_fd("minishell :", base->std_out);
		ft_putstr_fd(" cd: HOME not set\n", base->std_out);
		base->zigzag = 0;
	}
}

t_list		*ft_find_path(t_list **env, char *to_find, char end)
{
	t_list	*tmp;

	tmp = *env;
	if (end == EMPTY)
		while (tmp)
		{
			if (ft_strncmp(tmp->str, to_find, ft_strlen(to_find)) == 0)
				return (tmp);
			tmp = tmp->next;
		}
	else
		while (tmp)
		{
			if ((ft_strncmp(tmp->str, to_find, ft_strlen(to_find)) == 0) &&
				(tmp->str[ft_strlen(to_find)] == end))
				return (tmp);
			tmp = tmp->next;
		}
	return (NULL);
}

static void	ft_move(t_list *pwd, t_list *oldpwd, t_list *path, t_base *base)
{
	char	*s_pwd;
	char	*s_oldpwd;
	char	*tmp;

	move_helper(&oldpwd, &s_oldpwd);
	if ((tmp = ft_strchr(path->str, '=')) == NULL)
		tmp = path->str;
	else
		tmp = tmp + 1;
	if (chdir(tmp) != 0)
		ft_error_cd(tmp, base, 1);
	else
	{
		(base->cd_flag == 1) ? ft_pwd() : 0;
		tmp = getcwd(NULL, 0);
		s_pwd = ft_strjoin("PWD=", tmp);
		free(tmp);
		if (pwd)
		{
			free(pwd->str);
			pwd->str = s_pwd;
		}
		else
			ft_lstadd_back(&base->env, new_list(s_pwd));
	}
}

static void	get_old_pwd(t_base *base, t_list **oldpwd)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	ft_lstadd_back(&base->env, new_list(ft_strjoin("OLDPWD=", tmp)));
	*oldpwd = ft_find_path(&base->env, "OLDPWD", EMPTY);
	free(tmp);
}

void		ft_cd(t_list *path, t_base *base)
{
	t_list	*pwd;
	t_list	*oldpwd;

	base->zigzag = 0;
	base->cd_flag = 0;
	if (path && ft_strcmp(path->str, "") == 0)
		return ;
	pwd = ft_find_path(&base->env, "PWD", EMPTY);
	oldpwd = ft_find_path(&base->env, "OLDPWD", EMPTY);
	if (path && (ft_strcmp(path->str, "-")) == 0 && oldpwd == NULL)
		return (ft_error_cd(NULL, base, 2));
	(oldpwd == NULL) ? get_old_pwd(base, &oldpwd) : 0;
	if (path && (ft_strcmp(path->str, "-")) == 0)
	{
		free(path->str);
		path->str = ft_strdup(ft_strchr((ft_find_path(&base->env,
			"OLDPWD", EQUAL))->str, '=') + 1);
		base->cd_flag = 1;
	}
	if (path == NULL &&
		((path = ft_find_path(&base->env, "HOME", EQUAL)) == NULL))
		return (ft_error_cd(NULL, base, 3));
	ft_move(pwd, oldpwd, path, base);
}
