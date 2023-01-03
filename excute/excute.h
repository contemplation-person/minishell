/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:14:07 by gyim              #+#    #+#             */
/*   Updated: 2023/01/03 14:33:09 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCUTE_H
# define EXCUTE_H
# include "../builtin_list/builtin_list.h"
# include "../minishell.h"

int		excute_leaf(t_tnode *cmd_list, t_fds *fd_info,
			t_env_info_list *envp_list);
void	print_error(char *cmd, char *msg);
int		excute_cmd(char **cmd, t_fds *fd_info, t_env_info_list *envp_list);
int		cmd_builtin_check1(char **cmd, t_env_info_list *envp_list);
int		cmd_builtin_check2(char **cmd, t_env_info_list *envp_list);
void	cmd_path_check(char **path, char **cmd,
			t_env_info_list *envp_list);

char	**get_path(t_env_info_list *envp_list);
void	free_path(char **path);

char	**get_cmd(t_tnode *head);
int		get_cmd_list_len(t_tnode *head);
void	free_cmd(char **cmd);

char	*envp_node_to_str(t_env_info *node);
char	**envp_list_to_arr(t_env_info_list *envp_list);

t_rnode	*get_redirection(t_tnode *cmd_list);
int		is_redirection(char *token);
void	add_redirection(t_rnode	**r_list, t_tnode *node);
t_rnode	*set_redirection(t_tnode *node);
void	set_fds(t_fds *fds, t_rnode *node);
void	free_red(t_rnode *rd_head);

int		set_outfile(t_fds *fds, t_rnode *node);
int		set_addfile(t_fds *fds, t_rnode *node);
int		set_infile(t_fds *fds, t_rnode *node);
int		set_here_doc(t_fds *fds, t_rnode *node);
#endif