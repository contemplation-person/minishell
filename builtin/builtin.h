/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:03 by juha              #+#    #+#             */
/*   Updated: 2022/12/18 12:29:34 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"
# include <sys/errno.h>

typedef enum e_bool
{
	FALSE,
	TRUE,
}t_bool;

typedef enum e_env_feature
{
	ENV,	// 전역변수
	EXPORT, // 지역변수
}t_env_feature;

typedef struct s_env_info
{
	char				*key;
	char				*value;
	t_env_feature		feature;
	int					index;
	struct s_env_info	*prev;
	struct s_env_info	*next;
}t_env_info;

typedef struct s_env_info_list
{
	int			cnt;
	t_env_info	*env_info;	
}t_env_info_list;

t_env_info	*new_env_list(char *env, t_env_feature feature);
void		add_env_list(t_env_info_list *list,\
						char *env, t_env_feature feature);
void		print_envp(t_env_info_list minishell_envp, t_env_feature feature);
void		delete_one_list(t_env_info_list *list, char *key);

int			cd(int argc, char **argv);
int			echo(int argc, char **argv);
t_bool		env(t_env_info_list *minishell_envp, char *str); //done
int			builtin_exit(int argc, char **argv);
t_bool		builtin_export(t_env_info_list *minishell_envp, char *export_str);
int			pwd(char *str); //done
t_bool		builtin_unset(t_env_info *l, char *unset_name);

#endif