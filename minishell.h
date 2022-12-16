/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:52:21 by juha              #+#    #+#             */
/*   Updated: 2022/12/16 20:08:25 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "parser/parser.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "prompt/prompt.h"
# include "excute/excute.h"
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

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

typedef struct s_node
{
	t_tnode			*op;
	t_tnode			*words;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;


#endif