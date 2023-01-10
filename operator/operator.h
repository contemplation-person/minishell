/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:36:28 by gyim              #+#    #+#             */
/*   Updated: 2023/01/10 19:22:07 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H
# include "../minishell.h"

int	op_infile(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list);
int	op_outfile(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list);
int	op_append(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list);
int	op_here_doc(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list);

int	op_double_and(t_tree_node *node, t_cplist **cmd_list,
		t_env_info_list *env_list);
int	op_double_or(t_tree_node *node, t_cplist **cmd_list,
		t_env_info_list *env_list);
#endif