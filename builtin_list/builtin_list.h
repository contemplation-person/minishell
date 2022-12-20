/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:03 by juha              #+#    #+#             */
/*   Updated: 2022/12/20 14:37:38 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_LIST_H
# define BUILTIN_LIST_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/errno.h>

//extern int	error_code;

typedef enum e_bool
{
	FALSE,
	TRUE,
}t_bool;

typedef enum e_env_feature
{
	ENV,
	EXPORT,
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

t_env_info	*new_env_list(char *env);
void		add_env_list(t_env_info_list *list,\
						char *env, t_env_feature feature);
void		print_envp(t_env_info_list minishell_envp, t_env_feature feature);
void		delete_one_list(t_env_info_list *list, char *key);
#endif