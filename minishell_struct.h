/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:32:14 by gyim              #+#    #+#             */
/*   Updated: 2023/01/05 20:24:47 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

# define CMD_NOT_FOUND ": command not found\n"
# define BASH		   "MINISHELL: "
# define NO_FILE_DIR	"No such file or directory\n"
# define HERE_DOC		"/here_doc.temp"

extern int	g_error_code;

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

typedef struct s_fds
{
	int	in_fd;
	int	out_fd;
}	t_fds;

typedef struct s_rnode
{
	int				redirection;
	char			*file;
	struct s_rnode	*next;
}	t_rnode;

#endif
