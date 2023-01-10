/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:14:07 by gyim              #+#    #+#             */
/*   Updated: 2023/01/10 19:26:55 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCUTE_H
# define EXCUTE_H
# include "../builtin_list/builtin_list.h"
# include "../minishell.h"

int			excute_leaf(t_tnode *cmd_list, t_fds *fd_info,
				t_env_info_list *envp_list);
void		print_error(char *cmd, char *msg);
int			excute_cmd(char **cmd, t_fds *fd_info, t_env_info_list *envp_list);
int			pipe_excute_cmd(char **cmd, t_fds *fd_info,
				t_env_info_list *envp_list);
int			excute_cmd_pipe_list(t_cplist **cmd_pipe_lists,
				t_env_info_list *env_list);
int			pipe_excute_leaf(t_tnode *cmd_list, t_fds *fd_info,
				t_env_info_list *envp_list);
int			cmd_builtin_check1(char **cmd, t_env_info_list *envp_list);
int			cmd_builtin_check2(char **cmd, t_env_info_list *envp_list);
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
				t_env_info_list *envp_list);
void		rd_list_add(t_rnode **rd_list, t_rnode *target);
void		excute_list_add(t_cplist **cmd_list, t_tnode *cmds,
				t_env_info_list *env_list);
t_cplist	*init_cmd_pipe_lists(void);

void		free_cmd_pipe_list(t_cplist **cmd_pipe_lists);
void		free_cmd_list(t_cmd_node *head);
char		*merge_token(t_tnode *head);

void		print_cmd_pipe_list(t_cplist *list);
void		print_cmds(char **cmd);

#endif
