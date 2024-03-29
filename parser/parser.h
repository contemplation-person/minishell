/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:43:32 by gyim              #+#    #+#             */
/*   Updated: 2023/01/18 10:03:03 by gyim             ###   ########seoul.kr  */
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
void			del_list(t_tlist_info *list);

t_tlist_info	*split_input(char *input);
int				get_token(t_tlist_info *list, char *input, int start);
void			add_substr(t_tlist_info *list, char *str, int start, int end);
int				get_op_end(char *input, int start);
int				get_word_end(char *input, int start);
int				is_space(char ch);
int				is_paren(char *input, int index);
int				is_op(char *input, int index);
t_tree_node		*parser(t_tlist_info *list);

int				parsing_excute(char *user_input, t_fds *fds,
					t_env_info_list *env_list);
t_tree_node		*make_tree(t_tnode *head);
t_tree_node		*make_new_node(void);
void			free_tlist(t_tnode *head);
int				make_child(t_tree_node *parent_node,
					t_tnode *head, t_tnode *op_node);
void			del_tree(t_tree_node *node);
t_tnode			*find_op(t_tnode *head);
t_tnode			*find_last_node(t_tnode *head);
void			add_token_list(t_tnode **head, char *token);
t_tnode			*replace_list(t_tnode **head, t_tnode *prev,
					t_tnode *target, t_tnode *new_list);

t_tnode			*find_prev(t_tnode *head, t_tnode *target);
t_tnode			*check_double_op(t_tnode *head);
t_tnode			*check_pipe_op(t_tnode *head);
t_tnode			*check_redirect(t_tnode	*head);

int				valid_check(t_tnode *head);
int				in_quote_check(char ch, int in_quote);
int				quote_check(t_tnode *head);
int				paren_check(t_tnode *head);
int				grammar_check(t_tnode *head);
int				tree_valid_check(t_tree_node *node);
char			*find_variable(char *token, int start, int end,
					t_env_info_list *env_list);
void			dollar_token_change(char **ret, char *token,
					t_env_info_list *env_list);
void			check_quote(char *token, int *i, int *double_quote);
void			*ft_strjoin_free(char **ret, char *temp, char *prev);
char			*dollar_expand(char *token, int start, int end,
					t_env_info_list *env_list);
char			*p_token_expansion(char *token, t_env_info_list *env_list);
char			*error_code_expansion(char *token, int start, int end);
char			*env_key_to_value(char *token, int start, int end,
					t_env_info_list *env_list);
void			skip_s_quote(char *token, int *index);
int				expansion(t_tnode *head, t_env_info_list *env_list);
void			retokenize(t_tnode	*head);
void			skip_d_quote(char *token, int *index);
t_tnode			*split_token(char *token);

void			multiple_cmds_excute(t_tlist_info *word_list,
					t_fds *fds, t_env_info_list *env_list);
void			ret_make_asterisk(char *change_token,
					char **sub_token);
void			make_asterisk(char **sub_token);
char			*asterisk(char *token);
void			smart_join(char	**first_str, char *second_str);
int				analyze_patten(char *sub_token, char *d_name,
					int *sub_idx, int *d_idx);
int				is_same_patten(char *sub_token, char *d_name);
void			quote_remove(t_tnode *cmd_list);
char			*remove_token_quote(char *token);
void			change_quote_char(char *token);
char			*concat_str(char **splitted);
void			free_splitted(char **splitted);
int				is_word(char *target);
int				is_pipe(char *target);
int				is_double_op(char *target);
int				is_parenthesis(char *target);
int				op_valid_check(t_tnode *prev, t_tnode *curr);
#endif
