/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:09:17 by sbroderi          #+#    #+#             */
/*   Updated: 2020/11/07 21:23:56 by ftorn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "structures.h"
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# define QUOTE 39
# define WQUOTE 34
# define EMPTY 'e'
# define TERM '\0'
# define EQUAL '='

extern int	g_read;
extern int	g_status;

int			get_next_line(int fd, char **line);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_strcmp(const char *str1, const char *str2);
char		*ft_strdup(const char *s1);
t_list		*new_list(char *str);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst);
int			ft_strlen(char *str);
char		*ft_strjoin_char(char *str, char c);
void		ft_cd(t_list *path, t_base *base);
void		ft_pwd(void);
char		*ft_find_quote(char *src, int *index, t_base *base);
char		*ft_find_word(char *src, int *index, t_base *base);
char		*ft_find_double_quote(char *src, int *index, t_base *base);
int			ft_dollar(char **content, t_base *base, char *src);
char		*find_env_arg(t_base *base, char *str);
void		ft_start_error(int argc, char *argv[]);
int			ft_isdigit(int c);
t_list		*ft_copy_list(t_list *list);
void		ft_swap_str(char **s1, char **s2);
void		ft_print(t_list *env, t_list *args, char flag);
void		ft_sort_list(t_list *list);
void		ft_export(t_base *base);
t_list		*ft_find_path(t_list **env, char *to_find, char end);
int			ft_isalpha(int c);
void		ft_unset(t_base *base);
int			ft_shield(char **content, char *src);
void		ft_hidden(int code);
void		ft_prompt(int argc, char *argv[]);
void		ft_echo(t_base *base);
void		ft_command_selector(t_base *base, int *hidden_code);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		**ft_split(char const *s, char c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_exe(t_base *base, char *str);
void		ft_handle_pipe(t_base *base);
int			ft_handle_redir(char *line, t_base *base);
void		ft_data_parser(t_base *base, char *line);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_handle_rev_redir(char *line, t_base *base);
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
void		ft_exit(t_base *base);
int			ft_check_arg(char *arg, t_base *base);
int			check_bracket(t_base *base);
void		fill_new_value_export(char **new_value, char ch);
int			print_err_massage_export(t_list **tmp, t_base *base);
void		ft_print_export_err(char *str, t_base *base);
char		*ft_get_elem_from_split(char **for_split, t_base *base);
void		fill_res(char **res, t_base *base);
char		**ft_array(t_list *arguments);
void		ft_error_exe(t_base *base, char *command, int code);
void		move_helper(t_list **oldpwd, char **s_oldpwd);
int			ft_shield(char **content, char *src);
void		ft_handle_semicolon(t_base *base);
void		ft_copy_env(t_base *base, char **env);
int			ft_check_redir_arg(char *line);
int			ft_check_rev_redir_arg(char *line);
void		ft_fill_content_tmp(char **content, char **tmp);
int			ft_check_double_pipe_semicolon(char *line);
void		ft_sigint(void);
void		ft_sigquit(void);
void		ft_skip_spases(char **line, int *j);
int			selector(char **line, int *j, t_base *base, char **content);
int			check_semicolon(char **line, int *j, t_base *base);
int			check_pipe(char **line, int *j, t_base *base);
int			check_redirrect(char **line, int *j, t_base *base, char **content);
int			check_end_redirect(t_base *base, char *str);
int			ft_check_tail(char **line, char **tail);
int			check_rev_redirrect(char **line, int *j,
	t_base *base, char **content);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

#endif
