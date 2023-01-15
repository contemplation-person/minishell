/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:14:07 by gyim              #+#    #+#             */
/*   Updated: 2023/01/16 02:07:21 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCUTE_H
# define EXCUTE_H
# include "../minishell.h"

int			excute_leaf(t_tnode *cmd_list, t_fds *fd_info,
				t_env_info_list *envp_list);
void		print_error(char *cmd, char *msg);
int			excute_cmd(t_cplist *cmd_node, t_env_info_list *envp_list);
int			cmd_builtin_check1(char **cmd, t_env_info_list *envp_list);
int			cmd_builtin_check2(char **cmd, t_env_info_list *envp_list);
void		excute_all(t_cplist *cmd_pipe_list,
				t_fds *fds, t_env_info_list *envp_list);
char		**get_path(t_env_info_list *envp_list);
void		free_path(char **path);

char		**get_cmd(t_tnode *head);
int			get_cmd_list_len(t_tnode *head);
void		free_cmd(char **cmd);
void		cmd_path_check(char **path, char **cmd,
				t_env_info_list *envp_list);

char		*envp_node_to_str(t_env_info *node);
char		**envp_list_to_arr(t_env_info_list *envp_list);

void		free_red(t_rnode *rd_head);

void		search_tree(t_tree_node *node, t_cplist **cmd_list,
				t_fds *fds, t_env_info_list *envp_list);
void		excute_list_add(t_cplist **cmd_list, t_tnode *cmds,
				t_env_info_list *env_list);
int			op_double_and(t_tree_node *node, t_cplist **cmd_list,
				t_fds *fds, t_env_info_list *env_list);
int			op_double_or(t_tree_node *node, t_cplist **cmd_list,
				t_fds *fds, t_env_info_list *env_list);

t_cplist	*new_cplist(void);
char		*get_cplist_cmd(t_tnode *cmds,
				t_env_info_list *env_list);
int			cplist_len(t_cplist *cmd_pipe_list);

void		free_cmd_pipe_list(t_cplist **cmd_pipe_lists);
char		*merge_token(t_tnode *head);

void		reset_fds(t_fds *fds);
void		init_fds(t_fds *fds);

void		create_heredoc(t_cplist *cplist);
//int			get_heredoc_fd(t_rnode *rd);

char		**split_cmd(char *cmd);
void		remove_all_token_quote(t_tnode **head);
char		**all_token_to_cmds(t_tnode **head);

#endif
