/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:25:16 by gyim              #+#    #+#             */
/*   Updated: 2023/01/04 11:29:15 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H
# include "../minishell.h"

t_rnode	*get_redirection(t_tnode *cmd_list);
int		is_redirection(char *token);
void	add_redirection(t_rnode	**r_list, t_tnode *node);
t_rnode	*set_redirection(t_tnode *node);
int		set_fds(t_fds *fds, t_rnode *node);

int		set_outfile(t_fds *fds, t_rnode *node);
int		set_addfile(t_fds *fds, t_rnode *node);
int		set_infile(t_fds *fds, t_rnode *node);
int		set_here_doc(t_rnode *node);
void	free_red(t_rnode *rd_head);

int		read_lines(int here_doc_fd, char *limiter);
#endif