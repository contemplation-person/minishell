/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:36:28 by gyim              #+#    #+#             */
/*   Updated: 2023/01/13 18:49:18 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H
# include "../minishell.h"

int	op_double_and(t_tree_node *node, t_cplist **cmd_list, 
		t_fds *fds, t_env_info_list *env_list);
int	op_double_or(t_tree_node *node, t_cplist **cmd_list,
		t_fds *fds, t_env_info_list *env_list);
#endif