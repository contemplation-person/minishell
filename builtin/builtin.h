/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:03 by juha              #+#    #+#             */
/*   Updated: 2023/01/17 15:03:32 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"
# include "../builtin_list/builtin_list.h"

void		builtin_error_message(char *name, char *error, \
									char *message, int error_code);
int			cnt_argc(char **excute_str_form);
t_bool		builtin_cd(
				t_env_info_list *minishell_envp, char **excute_str_form);
t_bool		echo(char **excute_str_form);
t_bool		builtin_env(
				t_env_info_list *minishell_envp, char **excute_str_form);
int			builtin_exit(
				char **excute_str_form);

t_bool		builtin_export(
				t_env_info_list *minishell_envp, char **export_str);
void		builtin_pwd(void);
t_bool		builtin_unset(t_env_info_list *l, char **unset_name);

int			is_unchanged_dir(t_env_info_list *envp, \
							char **old_pwd, char *new_pwd);
t_env_info	*find_env(t_env_info_list *envp, char *key);
#endif