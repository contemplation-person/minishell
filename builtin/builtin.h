/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:03 by juha              #+#    #+#             */
/*   Updated: 2022/12/20 18:30:13 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../builtin_list/builtin_list.h"

//extern int	error_code;

t_bool		builtin_error_message(char *builtin, char *error, char *message);

int			cd(int argc, char **argv);
int			echo(int argc, char **argv);
t_bool		env(t_env_info_list *minishell_envp, char *str); //done
int			builtin_exit(int argc, char **argv);
t_bool		builtin_export(t_env_info_list *minishell_envp, char **export_str);//doen
int			pwd(char *str); //done
t_bool		builtin_unset(t_env_info_list *l, char **unset_name);

#endif