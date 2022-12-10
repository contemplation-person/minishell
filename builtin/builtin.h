/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:03 by juha              #+#    #+#             */
/*   Updated: 2022/12/10 22:49:52 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"
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
	struct s_env_info	*prev;
	struct s_env_info	*next;
}t_env_info;

t_env_info	*new_env_list(char *key, char *value, t_env_feature feature);
t_env_info	*init_env(char **envp);
void		print_envp(t_env_info *envp);
void		remove_env_list(t_env_info **list);

int			cd(int argc, char **argv);
int			echo(int argc, char **argv); //done
t_bool		env(t_list *list, int argc);
int			builtin_exit(int argc, char **argv);
t_bool		builtin_export(t_env_info *minishell_envp, int argc, char *env);
int			pwd(int argc); //done
t_bool		builtin_unset(t_env_info *l, char *unset_name);

#endif