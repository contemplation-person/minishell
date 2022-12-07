/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:43:32 by gyim              #+#    #+#             */
/*   Updated: 2022/12/07 19:40:00 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_INPUT_H
# define SPLIT_INPUT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

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
	char			*op;
	char			**words;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

// token_list.c
t_tlist_info	*tlist_init(void);
t_tnode			*make_node(char *str);
t_tnode			*lst_last(t_tlist_info *list_info);
void			list_add(t_tlist_info *list, char *str);
void			del_list(t_tlist_info *list);
int				list_len(t_tlist_info *list);

// split_input.c
t_tlist_info	*split_input(char *input);
int				get_token(t_tlist_info *list, char *input, int start);
int				get_op_end(char *input, int start);
int				get_quoted_end(char *input, int start);
int				get_word_end(char *input, int start);
void			add_substr(t_tlist_info *list, char *str, int start, int end);
// token_check.c
int				is_space(char ch);
int				is_quote(char *input, int index);
int				is_brace(char *input, int index);
int				is_op(char *input, int index);
// parser.c
t_node			*parser(t_tlist_info *list);
char			**get_cmds_from_list(t_tlist_info *list);
int				list_len(t_tlist_info *list);
void			copy_from_list(char **target, t_tlist_info *list);
// tree.c
t_node			*make_tree(char **cmds);
t_node			*make_new_node(void);
int				make_child(t_node *parent_node, char **cmds, int op_index);
void			del_tree(t_node *node);
// utils.c
int				find_op(char **cmds);
char			**subcmds(char **cmds, int start, int end);
int				cmds_len(char **cmds);
void			free_cmds(char **cmds);
void			print_cmds(char **cmds);
#endif

// gcc -lreadline -L../readline -I../readline $(your *.c file)
