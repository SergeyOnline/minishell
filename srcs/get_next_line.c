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

static int		cut_line(char **new_line, char **tail)
{
	*(*new_line) = '\0';
	if (!(*tail = ft_strdup(*new_line + 1)))
		return (-1);
	return (0);
}

static void		gnl_error(void)
{
	ft_putstr_fd("exit\n", 1);
	exit(1);
}

static int		gnl_main(char ***line, char buf[], char **tail)
{
	char *ptr;
	char *new_line;

	if ((new_line = ft_strchr(buf, '\n')))
		if ((cut_line(&new_line, tail)) == -1)
			return (-1);
	ptr = **line;
	if (!(**line = ft_strjoin(**line, buf)))
		return (-1);
	free(ptr);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	long		read_bytes;
	static char *tail;
	int			flag;
	int			gnl;

	read_bytes = 0;
	flag = 0;
	if (fd == -1 || (ft_check_tail(line, &tail)) == 1)
		return (-1);
	while (!tail && (read_bytes = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		if (read_bytes == 0)
			ft_putstr_fd("  \b\b", 1);
		(read_bytes == 0 && g_read == 0) ? gnl_error() : 0;
		g_read = 1;
		buf[read_bytes] = '\0';
		gnl = gnl_main(&(line), &(buf[0]), &tail);
		if (gnl == 1)
			continue;
		else if (gnl == -1)
			return (-1);
	}
	return ((read_bytes || tail) ? 1 : 0);
}
