/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:43:32 by gyim              #+#    #+#             */
/*   Updated: 2022/12/17 13:13:15 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../minishell.h"
# include "../libft/libft.h"
# include "../excute/excute.h"
# include <stdlib.h>

// prompt.c
void			print_list(t_tnode *head);

// token_list.c
t_tlist_info	*tlist_init(void);
t_tnode			*make_node(char *str);
t_tnode			*lst_last(t_tlist_info *list_info);
void			list_add(t_tlist_info *list, char *str);
void			del_list(t_tlist_info *list);
int				list_len(t_tlist_info *list);
// token_list2.c
t_tnode			*delete_paren(t_tnode *head);
t_tnode			*last_prev_node(t_tnode *head);
void			print_list(t_tnode *head);

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
int				is_paren(char *input, int index);
int				is_op(char *input, int index);
// parser.c
t_node			*parser(t_tlist_info *list);
char			**get_cmds_from_list(t_tlist_info *list);
int				list_len(t_tlist_info *list);
void			copy_from_list(char **target, t_tlist_info *list);
int				parsing_excute(char *user_input);
// tree.c
t_node			*make_tree(t_tnode *head);
t_node			*make_new_node(void);
int				make_child(t_node *parent_node,
					t_tnode *head, t_tnode *op_node);
void			del_tree(t_node *node);
void			free_list(t_tnode *head);
// utils.c
t_tnode			*find_op(t_tnode *head);
char			**subcmds(char **cmds, int start, int end);
int				cmds_len(char **cmds);
void			free_cmds(char **cmds);
void			print_cmds(char **cmds);
// utils2.c
t_tnode			*find_prev(t_tnode *head, t_tnode *target);
t_tnode			*check_double_op(t_tnode *head);
t_tnode			*check_pipe_op(t_tnode *head);
t_tnode			*check_redirect(t_tnode	*head);
// validate_check.c
int				valid_check(t_tnode *head);
int				quote_check(char *token);
int				paren_check(t_tnode *head);
// search_tree.c
int				excute_tree(t_node *node);
#endif

// gcc -lreadline *.c libft.a -L../readline -I../readline 