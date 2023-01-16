/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:03 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 15:42:59 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_LIST_H
# define BUILTIN_LIST_H

# include "../libft/libft.h"
# include <stdio.h>
# include <sys/errno.h>

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
void		add_env_list(t_env_info_list *list, \
					char *env, t_env_feature feature);
void		print_envp(t_env_info_list minishell_envp, t_env_feature feature);
void		delete_one_list(t_env_info_list *list, char *key);
void		init_list(t_env_info_list *list, char **envp);

void		env_node_free(t_env_info **node);
#endif