/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:43:32 by gyim              #+#    #+#             */
/*   Updated: 2023/01/06 12:37:19 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../minishell.h"

t_tlist_info	*tlist_init(void);
t_tnode			*make_node(char *str);
t_tnode			*lst_last(t_tlist_info *list_info);
void			list_add(t_tlist_info *list, char *str);

t_tnode			*delete_paren(t_tnode *head);
t_tnode			*last_prev_node(t_tnode *head);
void			print_list(t_tnode *head);
void			del_list(t_tlist_info *list);
void			del_sublist(t_tnode	*head);

t_tlist_info	*split_input(char *input);
int				get_token(t_tlist_info *list, char *input, int start);
void			add_substr(t_tlist_info *list, char *str, int start, int end);
int				get_op_end(char *input, int start);
int				get_quoted_end(char *input, int start);
int				get_word_end(char *input, int start);
int				is_space(char ch);
int				is_quote(char *input, int index);
int				is_paren(char *input, int index);
int				is_op(char *input, int index);
t_tree_node		*parser(t_tlist_info *list);
char			**get_cmds_from_list(t_tlist_info *list);
int				list_len(t_tlist_info *list);
void			copy_from_list(char **target, t_tlist_info *list);
int				parsing_excute(char *user_input, t_env_info_list *env_list);
t_tree_node		*make_tree(t_tnode *head);
t_tree_node		*make_new_node(void);
void			free_tlist(t_tnode *head);
int				make_child(t_tree_node *parent_node,
					t_tnode *head, t_tnode *op_node);
void			del_tree(t_tree_node *node);
void			free_list(t_tnode *head);
t_tnode			*find_op(t_tnode *head);
t_tnode			*find_last_node(t_tnode *head);
void			add_token_list(t_tnode **head, char *token);
t_tnode			*replace_list(t_tnode **head, t_tnode *prev,
					t_tnode *target, t_tnode *new_list);

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
int				in_quote_check(char ch, int in_quote);
int				quote_check(t_tnode *head);
int				paren_check(t_tnode *head);
// search_tree.c
int				tree_valid_check(t_tree_node *node);
int				search_tree(t_tree_node *node,
					t_fds *fd_info, t_env_info_list *env_list);
// dollar_expannsion.c
char			*find_variable(char *token, int start, int end,
					t_env_info_list *env_list);
void			dollar_token_change(char **ret, char *token,
					t_env_info_list *env_list);
char			*dollar_expand(char *token, int start, int end,
					t_env_info_list *env_list);
char			*p_token_expansion(char *token, t_env_info_list *env_list);
void			skip_s_quote(char *token, int *index);
// param_expansion.c
int				expansion(t_tnode *head, t_env_info_list *env_list);
void			retokenize(t_tnode	*head);
void			skip_d_quote(char *token, int *index);
t_tnode			*split_token(char *token);
// pipe_excute.c
int				op_pipe(t_tree_node *node, t_fds *fd_info,
					t_env_info_list *env_list);
int				op_pipe_left_excute(t_tree_node *node,
					t_fds *fd_info, int fd[2], t_env_info_list *env_list);
int				op_pipe_right_excute(t_tree_node *node,
					t_fds *fd_info, int fd[2], t_env_info_list *env_list);
// cmds_check.c
int				multiple_cmds_check(t_tlist_info *word_list);
void			one_cmd_excute(t_tlist_info *word_list,
					t_env_info_list *env_list);
void			multiple_cmds_excute(t_tlist_info *word_list,
					t_env_info_list *env_list);
// 	redirection_excute.c
int				op_infile(t_tree_node *node, t_fds *fd_info,
					t_env_info_list *env_list);
int				op_outfile(t_tree_node *node, t_fds *fd_info,
					t_env_info_list *env_list);
int				op_append(t_tree_node *node, t_fds *fd_info,
					t_env_info_list *env_list);
// asterisk_1.c
void			ret_make_asterisk(char *change_token,
					char **sub_token);
void			make_asterisk(char **sub_token);
char			*asterisk(char *token);
// asterisk_2.c
int				analyze_patten(char *sub_token, char *d_name,
					int *sub_idx, int *d_idx);
int				is_same_patten(char *sub_token, char *d_name);
// quote_remove.c
void			quote_remove(t_tnode *cmd_list);
char			*remove_token_quote(char *token);
void			change_quote_char(char *token);
char			*concat_str(char **splitted);
void			free_splitted(char **splitted);
#endif
