/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:36:28 by gyim              #+#    #+#             */
/*   Updated: 2022/12/28 16:59:13 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H
# include "../minishell.h"

int	op_infile(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list);
int	op_outfile(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list);
int	op_append(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list);
int	op_here_doc(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list);
int	read_lines(char *limiter, int out_fd);
#endif