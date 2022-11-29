/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:10:54 by gyim              #+#    #+#             */
/*   Updated: 2022/11/29 11:21:53 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef enum e_check_list
{
	BRACKET = 1,
	SQUARE_BRACKET,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	BACKTICK,
}	t_check_list;

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum e_op
{
	D_AMP = 1,
	D_PIPE,
	PIPE
}	t_op;

typedef struct s_node
{
	char			**token;
	int				op;
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

//pair.c
t_stack_node	*pop_linked_stack(t_linked_stack *stack);
int				push_linked_stack(t_linked_stack *stack, int data);
t_linked_stack	*create_linked_stack(void);
void			input_a_pair_stack(t_linked_stack **in_stack, char c);
int				is_a_pair_stack(t_linked_stack **in_stack, char c);
int				delete_stack(t_linked_stack *stack);
// tree.c
t_node			*make_tree(char **token);
int				make_sub_tree(t_node *node, int token_len);
char			**get_sub_token(char **token, int start, int end);
// operator.c
int				op_check(char *token);
int				get_op_index(char **token);
//token.c
int				get_token_len(char **token);
int				p_start_check(char *token);
int				p_end_check(char *token);
char			**get_left_tokens(char *tokens[], int index);
char			**get_right_tokens(char *tokens[], int index, int size);

// for test
void			print_tree(t_node *node);
void			print_token(char **token);
#endif