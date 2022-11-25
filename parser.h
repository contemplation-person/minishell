/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:10:54 by gyim              #+#    #+#             */
/*   Updated: 2022/11/25 21:24:47 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef enum e_check_list
{
	BRACKET = 1,
	SQUARE_BRACKET,
	SINGLE_SQUOTE,
	DOUBLE_SQUOTE,
	BACKTICK,
}t_check_list;

typedef enum e_bool
{
	FALSE,
	TRUE,
}t_bool;

typedef struct s_node
{
	char			**tokens;
	// int				op;
	char			*op;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_stack_node
{
	int					data;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}t_stack_node;

typedef struct s_linked_stack
{
	int				cnt;
	t_stack_node	*head;
}t_linked_stack;

// parse_tree.c
t_node	*parse_tree(char **tokens);
int		make_child(t_node *parent, char **tokens, int index);
int		get_tokens_size(char **token);
int		op_check(char **tokens);
int		is_op(char *token);
#endif