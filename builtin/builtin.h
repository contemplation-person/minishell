/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:03 by juha              #+#    #+#             */
/*   Updated: 2022/12/23 15:19:29 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../builtin_list/builtin_list.h"

extern int	g_error_code;

void		builtin_error_message(char *name, char *error, \
									char *message, int error_code);

int			cd(char **excute_str_form); // pipe 갯수 판단, main 실행인지, subshell실행인지 판단.
int			echo(char **excute_str_form); 
t_bool		builtin_env(t_env_info_list *minishell_envp, char **excute_str_form); //done
int			builtin_exit(char **excute_str_form); // pipe 갯수 판단, main 실행인지, subshell실행인지 판단.
t_bool		builtin_export(t_env_info_list *minishell_envp, char **export_str); //done
void		builtin_pwd(char **excute_str_form); //done
t_bool		builtin_unset(t_env_info_list *l, char **unset_name);//done

#endif