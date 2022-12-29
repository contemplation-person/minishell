/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:14:07 by gyim              #+#    #+#             */
/*   Updated: 2022/12/29 17:25:48 by gyim             ###   ########seoul.kr  */
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

#endif