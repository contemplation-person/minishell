/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:32:14 by gyim              #+#    #+#             */
/*   Updated: 2022/12/20 11:31:15 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

typedef enum e_check_list
{
	BRACKET = 1,
	SQUARE_BRACKET,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	BACKTICK,
}	t_check_list;

typedef struct s_tnode
{
	char			*token;
	struct s_tnode	*next;
}	t_tnode;

typedef struct s_tlist_info
{
	t_tnode	*head;
	int		cnt;
}	t_tlist_info;

typedef struct s_tree_node
{
	t_tnode				*op;
	t_tnode				*words;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}	t_tree_node;

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
}	t_env_info;

typedef struct s_env_info_list
{
	int			cnt;
	t_env_info	*env_info;	
}	t_env_info_list;

#endif